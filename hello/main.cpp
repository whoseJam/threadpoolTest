#include <iostream>
#include <assert.h>
#include <thread>

#include "Pool.h"

using namespace std;

void fun(int sec, int id, string word) {
	for (int i = 1; i <= sec; i++){
		cout << word;
		this_thread::sleep_for(1s);
	}
}

int main(){
	Thpool pool = {4};
	pool.push(Task(fun, 2, 1, "hello\n").id(1));
	pool.push(Task(fun, 10, 2, "bye\n").id(2));
	pool.push(Task(fun, 2, 3, "good\n").id(3));
	pool.push(Task(fun, 5, 4, "english\n").id(4));
	pool.push(Task(fun, 1, 5, "dish\n").id(5));	
	cout << "job is init\n";
	pool.shutDown();
	cout << "all have been done\n";
	
	assert(pool.taskQueueSize() == 0);
	return 0;
}
