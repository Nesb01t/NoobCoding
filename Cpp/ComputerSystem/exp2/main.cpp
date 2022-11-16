#include <iostream>
#include <vector>
using namespace std;

class doubleMini {
public:
    doubleMini(float f) {
        unsigned char *p = (unsigned char*) &f;
        for (int i = 0; i < 4; i++) {
            b[i] = *(p + i);
            sixteenToTwo(b[i], i); // 置入char数据
        }
    }

    void sixteenToTwo(unsigned char c, int block) { // 区块置入数据
        int n = (int) c;
        int pos = 0; // 置入数组起始位
        while (c > 0 || pos != 8) {
            a[(block)*8+pos] = c%2; 
            pos++; c /= 2;
        }

        pos = 0;
        for (int i = 31; i > 0; i--) {
            data[pos++] = a[i];
        }
    }
    
    void printData() { // 输出
        for (auto i:data) {
            cout<<(int) i;
        }
    }

    float getData() {
        unsigned char S = data[0];
        int E = 0, M = 0, pos = 1;
        
        for(int i = 8; i > 0; i--) {
            E += (int)data[i]*pos;
            pos *= 2;
        }
        E -= 127; // offset

        vector<int> v;
        for(int i = 31; i > 8; i--) { // 获取M串
            v.insert(v.begin(), (int)data[i]);
        }
        
        if ( E > 0 ) {
            v.insert(v.begin(), 1);
            if (v.size() >= E) {
                v.insert(v.begin()+E+1, 88);
            } else {
                while(v.size() < E) {
                    v.push_back(0);
                }
                v.push_back(88);
            }
        } else if ( E < 0 ) {
            while ( E != 0 ) {
                v.insert(v.begin(), 0);
                E++;
            }
            v.insert(v.begin(), 88);
        }

        int i = 0;
        int big = 0;
        float small = 0.0f;
        for(; v[i] != 88; i++){
            big = big * 2 + v[i];
        }
        i++;
        float pow = 1.0f/2;
        for(; i < v.size(); i++){
            small = small + pow * v[i];
            pow /= 2;
        }
        return big + small;
    }
    unsigned char a[32]; // 反的二进制数据
    unsigned char b[4]; // float转4个8bit char值

    unsigned char data[32];
};
int main() {
    float debugger_num = 5.75;

    doubleMini f(debugger_num);
    f.printData();
    cout<<endl<<f.getData();
    return 0;
}