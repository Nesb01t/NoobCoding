#include "myVector.h"
#include <iostream>

using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    myVector<int> v = myVector<int>(a, 5);
    // ↓ insert your debugging code ↓

    v.insert(2, 1);
    v.debug_output();
    return 0;
}