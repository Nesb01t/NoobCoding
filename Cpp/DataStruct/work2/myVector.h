#include "myVector_func.h"

#define DEFAULT_CAPACITY 3

template <typename T>
class myVector{
protected:
    int _size;
    int _capacity;
    T* _elem;

    void copyFrom(T const* A, int lo, int hi);
    void expand();
    void bubbleSort(int lo, int hi);

public:
    myVector(T const* A, int n);
    myVector(T const* A, int lo, int hi);
    myVector(myVector<T> const& V);
    myVector(myVector<T> const& V, int lo, int hi);
    ~myVector();
};