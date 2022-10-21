#include <iostream>
using namespace std;
int main(){
    int len;
    string x;
    cin>>x;
    len = x.length();
    while(len>0){
        for(int i=0;i<len;i++){
            cout<<x[i];
        }
        cout<<endl;
        len-=2;
    }
}