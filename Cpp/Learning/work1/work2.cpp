#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int y;
    if(x<-2){
        y = x*x-sin(x);
    }else if(x>2){
        y = sqrt(x*x+x+1);
    }else{
        y = pow(2, x)+x;
    }
    cout<<"结果是"<<y<<endl;
}