
#include <iostream>
#include <chrono>

#include "Pool.h"

using namespace std;
using namespace std::chrono;

const int nTASK = 300;

void normalTask() {
    unsigned ans = 0;
    for (int i = 1; i <= 100000000; i++)
        ans = ans * 3 + 1;
}

void lightTaskTest(int count) {
    Thpool pool = {count};
    auto start = chrono::steady_clock::now();

    for (int i = 1; i <= nTASK; i++) {
        pool.push(Task(normalTask));
    }
    pool.shutDown();
    auto end = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Time = " << ms << " count = " << count << "\n";
}

int main() {
    for (int i = 1; i <= 16; i <<= 1) {
        lightTaskTest(i);
    }
    return 0;
}