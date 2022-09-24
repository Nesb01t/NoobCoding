#define DEFAULT_CAPACITY 3

template <typename T>
class myVector{
protected:
    int _size;
    int _capacity;
    T* _elem;
    
    void copyFrom(T const* source, int left, int right);
    void expand(){
        _elem = new T[_capacity];
    };
    void bubbleSort(int left, int right);
public:
    myVector(int c=DEFAULT_CAPACITY, int s=0, T v=0){ // 容量, 规模, 初始值
        s>c?s=c:;
        _capacity = c;_size = s;_elem = new T[_capacity];
        for(size_t i=0;i<_capacity;i++)_elem[i]=v;
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
    debug_output(){for(size_t i=0;i<_size;i++)std::cout<<_elem[i]<<endl;}
/* ---------- read only interface ---------- */


/* ---------- writable interface ---------- */
};