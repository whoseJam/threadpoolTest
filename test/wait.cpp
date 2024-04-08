
#include <iostream>
#include <assert.h>
#include <thread>

#include "Pool.h"

using namespace std;

void normalTask() {
    this_thread::sleep_for(50ms);
}

void testWait1() {
    Thpool pool = {4};
    for (int i = 1; i <= 500; i++)
        pool.push(Task(normalTask));
    pool.wait();
    assert(pool.taskQueueSize() == 0);

    for (int i = 1; i <= 500; i++)
        pool.push(Task(normalTask));
    pool.wait();
    assert(pool.taskQueueSize() == 0);

    for (int i = 1; i <= 500; i++)
        pool.push(Task(normalTask));
    pool.wait();
    assert(pool.taskQueueSize() == 0);

    pool.shutDown();
    assert(pool.taskQueueSize() == 0);

    cout << "Thpool.wait Test 1 Passed!\n";
}

int main() {
    testWait1();
    return 0;
}