#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class DecToBin { // 十进制 -> 二进制
public:
    DecToBin(){ // 构造函数
        this->m = 0;
        this->newm = 0;
    }; 
    void toBin(){ // 转二进制
        int upper=int(fabs(this->m)); // 整数部分
        double under = fabs(this->m) - upper; //小数部分

        int under_len = 6; //处理小数长度
        vector<char> tmp;

        // ---------- 整数部分 ---------- 
        while(upper>0){
            tmp.insert(tmp.end(), char('0'+(upper%2)));
            upper/=2; this->newm++;
        }
        this->newm--;
        reverse(tmp.begin(), tmp.end());
        binStr.insert(binStr.end(), tmp.begin(), tmp.end());
        binStr.insert(binStr.end(), '.');

        // ---------- 小数部分 ---------- 
        while(under_len-->0 && under!=0){
            under*=2;
            binStr.insert(binStr.end(), char('0'+int(under)));
            under-=int(under);
        }
    };
    void toDec(){ // 转十进制
        int source = this->newm;
        int i = 0;
        this->newm = 0;
        while(source>=0){
            this->newm+=int(binStr[i]-'0')*pow(2, source);
            source--; i++;
        }
        source--; i++;

        while(source>-7){
            this->newm+=int(binStr[i]-'0')*pow(2, source);
            source--; i++;
        }
    }; 
    void getDec(){ // 输入数值
        cout<<"please input data: "<<endl;
        cin >> this->m;
    }; 
    void printData(){ //打印三个数
        cout<<"---------- data ----------"<<endl;
        cout<<"origin data is: "<<this->m<<endl;
        cout<<"computed data is: "<<this->newm<<endl;
        cout<<"binary data is: ";
        for(auto i:binStr){
            cout<<i;
        }
        cout<<endl;
    };
private:
    double m; // 数值
    double newm; // 从二进制转换过来的值
    vector<char> binStr; // 二进制值 String
};