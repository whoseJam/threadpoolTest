#include <iostream>
#include <assert.h>

#include "Pool.h"

using namespace std;

void add(int a, int b) {
    cout << a + b << '\n';
}

void sub(int &a, const int b) {
    a = a - b;
}

int main() {
    Task t1(add, 1, 2);
    t1.run();
    t1.run();

    int v = 10;
    Task t2(sub, v, 1);
    t2.run();
    t2.run();
    assert(v == 8);
    return 0;
}