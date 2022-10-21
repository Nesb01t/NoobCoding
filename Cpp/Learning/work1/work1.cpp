#include <iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int a = num % 10;
    int b = (num/10) % 10;
    int c = num/100;
    if(a*a*a+b*b*b+c*c*c==num){
        cout<<"是水仙花数!";
    }else{
        cout<<"不是水仙花数!";
    }
    return 0;
}