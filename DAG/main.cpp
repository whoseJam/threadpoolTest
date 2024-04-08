#include <iostream>
#include <assert.h>
#include <ctime>
#include <mutex>

#include "Pool.h"

using namespace std;

int R(int l, int r) {
	return rand() % (r - l + 1) + l;
}

const int N = 1005;

vector<int> G[N];
Thpool pool = {4};
int mark[N];

struct Data {
	int id;
	atomic<int> ind;
} D[N];

void solve(Data& myData){
	int id = myData.id;
	mark[id] = 1;

	for (int i = 0; i < G[id].size(); i++) {
		int v = G[id][i];
		D[v].ind--;
		if(D[v].ind==0) {
			Task task = {solve, ref(D[v])};
			pool.push(task);
		}
	}
}

void Link(int u, int v) {
	G[u].push_back(v);
	D[v].ind++;
}

int main(int argc, char** args) {
	srand(time(NULL));

	int n = atoi(args[1]);
	for (int i = 1; i <= n; i++) {
		D[i].id=i;
	}
	for (int i = 2; i <= n; i++) {
		while(R(1,4) <= 3) {
			Link(R(1, i-1), i);
		}
	}
	for (int i = 1; i <= n; i++)
		if(D[i].ind==0){
			pool.push(Task(solve, ref(D[i])));
		}
	pool.shutDown();
	cout<<"all have been done\n";

	assert(pool.taskQueueSize() == 0);
	for (int i = 1; i <= n; i++) {
		assert(mark[i] == 1);
	}
	return 0;
}