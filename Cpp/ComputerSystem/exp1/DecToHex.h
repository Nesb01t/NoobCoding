#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class DecToHex { // 十进制 -> 二进制
public:
    DecToHex(){ // 构造函数
        this->m = 0;
        this->newm = 0;
        hexStr.clear();
    }
    void toHex(){ // 转十六进制
        // 整数部分
        int a = int(m);
        vector<char> tmp;
        while(a>0){
            char key;
            if(a%16>=10){key='A'+(a%16)-10;}
            else{key='0'+(a%16);};
            tmp.push_back(key);
            a/=16;
        }
        reverse(tmp.begin(), tmp.end());
        hexStr = tmp;

        // 小数部分
        hexStr.push_back('.');

        double b = m-int(m);
        double len = 0;
        vector<char> tmp_b;
        while(b!=0&&len<6){
            char key;
            if(b*16>=10){key='A'+int(b*16-10);}
            else if(b*16>=0) {key='0'+int(b*16);}
            else{key='0';}
            tmp_b.push_back(key);
            b=(b*16)-int(b*16); len++;
        }
        for(auto i:tmp_b){
            hexStr.push_back(i);
        }
    };
    void toDec(){ // 转十进制
        vector<char> tmp = hexStr;
        vector<char> v_a; vector<char> v_b;

        // tmp值分至 v_a(整数) 和 v_b(小数)
        bool cross_point = false;
        for(int i=0; i<tmp.size();i++){
            if(tmp[i]=='.'){cross_point=true;}
            else if(cross_point){v_b.push_back(tmp[i]);}
            else {v_a.push_back(tmp[i]);}
        }
        reverse(v_a.begin(), v_a.end());

        // 遍历 v_a(整数)
        int ans_a = 0;
        int mi = 1;
        for(auto i:v_a){
            i>'9'?ans_a+=mi*int(i-'A'+10):ans_a+=mi*int(i-'0');
            mi*=16;
        }
        
        // 遍历 v_b(小数)
        double ans_b = 0.0;
        double mi_b = 1.0/16;
        for(auto i:v_b){
            i>'9'?ans_b+=mi_b*double(i-'A'+10):ans_b+=mi_b*double(i-'0');
            cout<<ans_b<<endl;
            mi_b/=16;
        }

        // 返回 Computed 数值至 newm
        newm = ans_a + ans_b;
    }; 
    void getHex(){ // 输入数值
        cout<<"please input data: "<<endl;
        cin >> this->m;
    }; 
    void printData(){ //打印三个数
        cout<<"---------- data ----------"<<endl;
        cout<<"origin data is: "<<this->m<<endl;
        cout<<"computed data is: "<<this->newm<<endl;
        cout<<"binary data is: ";
        for(auto i:hexStr){
            cout<<i;
        }
        cout<<endl;
    };
private:
    double m;
    double newm;
    vector<char> hexStr;
};