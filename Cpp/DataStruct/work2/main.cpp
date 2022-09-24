#include "myVector.h"
#include <iostream>

using namespace std;

int main() {
    myVector<int> a = myVector<int>(10, 3);
    a.debug_output();
    
    return 0;
}