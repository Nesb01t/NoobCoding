#define DEFAULT_CAPACITY 3

#include <iostream>

template <typename T>
class myVector{
protected:
    int _size;
    int _capacity;
    T* _elem;
    
    void copyFrom(T const* source, int left, int right){for(int i=left;i<=right; i++)_elem[i-left] = source[i];};
    void expand(){
        _capacity*=2;
        T* __elem = new T[_capacity];
        for(int i=0;i<_capacity>>2;i++){
            __elem[i]=_elem[i];
            __elem[i+_capacity>>2]=0;
        }
    };
    void bubbleSort(int left, int right){
        for(int i=left;i<right-1;i++){
            for(int j=i;j<right-1;j++){
                if(_elem[j]>_elem[j+1])swap(_elem[j], _elem[j+1]);
            }
        }
    };
public:
    myVector(int c=DEFAULT_CAPACITY, int s=0, T v=0){ // 容量, 规模, 初始值
        if(s>c)c=s;
        _capacity = c;_size = s;_elem = new T[_capacity];
        for(int i=0;i<_capacity;i++)_elem[i]=v;
    };
    myVector(T const* source, int n){ // 源, 长度
        _capacity = n*2;_size = n;_elem = new T[_capacity];
        copyFrom(source, 0, n-1);
    };
    myVector(T const* source, int left, int right){ // 源, 左右端
        _capacity = 2*(right-left);_size = right-left;_elem = new T[_capacity];
        copyFrom(source, left, right);
    };
    myVector(myVector<T> const& source){ // 拷贝函数
        int s = source.getSize();
        _capacity = 2*s;_size = s;_elem = new T[_capacity];
        for(int i=0;i<s;i++)_elem[i]=source[i];
    };
    myVector(myVector<T> const& source, int left, int right){ // 区间拷贝函数
        int s = right-left;
        _capacity = 2*s;_size = s;_elem = new T[_capacity];
        for(int i=0;i<s;i++)_elem[i]=source[left+i];
    };
    ~myVector(){delete[] _elem;};
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
    T& operator[](int r){return _elem[r];} // 下标操作符
    const T& operator[](int r)const{return _elem[r];} // 做右值时-下标操作符
};