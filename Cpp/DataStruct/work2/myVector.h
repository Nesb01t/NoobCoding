#define DEFAULT_CAPACITY 3

template <typename T>
class myVector{
protected:
    int _size;
    int _capacity;
    T* _elem;
    
    void copyFrom(T const* source, int left, int right);
    void expand();
    void bubbleSort(int left, int right);
public:
    myVector();
    myVector(T const* A, int n);
    myVector(T const* A, int lo, int hi);
    myVector(myVector<T> const& V);
    myVector(myVector<T> const& V, int lo, int hi);
    ~myVector();
/* ---------- read only interface ---------- */


/* ---------- writable interface ---------- */
};