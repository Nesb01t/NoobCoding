#define DEFAULT_CAPACITY 3

#include <iostream>

template <typename T>
class myVector{
protected:
    int _size;
    int _capacity;
    T* _elem;
    
    void copyFrom(T const* source, int left, int right);
    void expand(){
        _capacity*=2;
        T* __elem = new T[_capacity];
        for(int i=0;i<_capacity>>2;i++){
            __elem[i]=_elem[i];
            __elem[i+_capacity>>2]=0;
        }
    };
    void bubbleSort(int left, int right);
public:
    myVector(int c=DEFAULT_CAPACITY, int s=0, T v=0){ // 容量, 规模, 初始值
        if(s>c)c=s;
        _capacity = c;_size = s;_elem = new T[_capacity];
        for(int i=0;i<_capacity;i++)_elem[i]=v;
    };
    myVector(T const* A, int n){
        _elem = new T[n+1];

    };
    myVector(T const* A, int lo, int hi){

    };
    myVector(myVector<T> const& V);
    myVector(myVector<T> const& V, int lo, int hi);
    ~myVector(){
        delete[] _elem;
    };
/* ---------- debugger ---------- */ 
    void debug_output(){
        std::cout<<"capacity容量: "<<_capacity<<std::endl
            <<"size规模: "<<_size<<std::endl
            <<"elem数据: ";
        for(int i=0;i<_size;i++){
            std::cout<<_elem[i]<<" ";
        }
    }
/* ---------- read only interface ---------- */
    int getSize() const{return _size;}
    bool empty() const{return _size==0;}
    

/* ---------- writable interface ---------- */
};