#include <iostream>
using namespace std;
double lex(int n){
    double ans = 1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    double sum1 = 1;
    double sum2 = 1;
    for(int i=1;i<=n;i++){
        sum1+=1/lex(2*i+1);
    }
    int x = 1;
    int part = 1;
    while(part>0.000001){
        sum2+=part;
        x+=2;
        part=1/lex(x);
    }
    cout<<"第一种方式为: "<<sum1<<endl<<"第二种方式为: "<<sum2<<endl;
}