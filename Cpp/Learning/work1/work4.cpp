#include <iostream>
using namespace std;

int main(){
    int count = 0;
    int n = 36;
    for(int i=0;i<=36;i++){
        for(int j=0;j<=36;j++){
            for(int k=0;k<=36;k++){
                if(i*3+j*2+k/2==n){
                    count++;
                    cout<<"男人有"<<i<<"个 ";
                    cout<<"女人有"<<j<<"个 ";
                    cout<<"男孩有"<<k<<"个"<<endl;
                }
            }
        }
    }
    cout<<"一共有"<<count<<"种组合!";
}