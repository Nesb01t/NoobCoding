#include <time.h>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

default_random_engine engine(time_t(0));
uniform_int_distribution<int> randomInt(1, 100);

int main()
{
    // 输入N并初始化数组
    int N;   
    cin>>N;
    int arr[N];
    for(auto i=0;i<N;i++){
        arr[i] = randomInt(engine);
    }

    // 选择排序, 时间复杂度为O(n^2)
    for(auto i=0;i<N;i++){ // n+1
        int max_value = arr[i];
        int max_id = i;
        for(auto j=i;j<N;j++){ // n(n+1) 
            if (arr[j]>max_value){ // n(n+1)+1
                max_value = arr[j];
                max_id = j;
            }
        }
        swap(arr[i], arr[max_id]);
    }

    // 输出数组
    reverse(arr, arr+N);
    for(auto i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}