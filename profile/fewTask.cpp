
#include <iostream>
#include <chrono>

#include "Pool.h"

using namespace std;
using namespace std::chrono;

const int nTASK = 300;

void fewTask() {
    unsigned ans = 0;
    for (int i = 1; i <= 100000000; i++)
        ans = ans * 3 + 1;
}

void fewTaskTest(int count) {
    Thpool pool = {count};
    auto start = chrono::steady_clock::now();

    for (int i = 1; i <= 8; i++) pool.push(Task(fewTask));
    for (int i = 1; i <= 10; i++) fewTask();
    for (int i = 1; i <= 8; i++) pool.push(Task(fewTask));
    for (int i = 1; i <= 10; i++) fewTask();
    pool.shutDown();

    auto end = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time = " << ms << " count = " << count << "\n";
}

int main() {
    for (int i = 1; i <= 16; i <<= 1) {
        fewTaskTest(i);
    }

    return 0;
}