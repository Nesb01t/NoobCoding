#include "myVector.h"
#include <iostream>

using namespace std;

template <typename T>
void add(T x){ // 函数指针案例 -> myVector.traverse(add);
    x++;
}
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    myVector<int> v = myVector<int>(a, 5);
    // ↓ 请输入您的测试代码 ↓ insert your debugging code ↓


    v.debug_output();
    return 0;
}