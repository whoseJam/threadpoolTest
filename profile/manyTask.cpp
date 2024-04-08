/**
 * 这一份测试点用来测试，当任务量比较多时，主线程等待线程池把工作做完，
 * 这种情况下，线程池的性能表现
 * 
*/
#include <iostream>
#include <chrono>

#include "Pool.h"

using namespace std;
using namespace std::chrono;

const int nTASK = 300;

void task() {
    unsigned ans = 0;
    for (int i = 1; i <= 100000000; i++)
        ans = ans * 3 + 1;
}

void manyTaskTest(int count) {
    Thpool pool = {count};
    auto start = chrono::steady_clock::now();

    for (int i = 1; i <= 80; i++) pool.push(Task(task));
    for (int i = 1; i <= 2; i++) task();
    for (int i = 1; i <= 80; i++) pool.push(Task(task));
    for (int i = 1; i <= 2; i++) task();
    pool.shutDown();

    auto end = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time = " << ms << " count = " << count << "\n";
}

int main() {
    for (int i = 1; i <= 16; i <<= 1) {
        manyTaskTest(i);
    }

    return 0;
}