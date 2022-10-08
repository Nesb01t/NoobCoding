#include <iostream>
#include <String>

using namespace std;

class CPU {
private:
    enum rank{
        P1=1,P2,P3,P4,P5,P6,P7
    };

    int frequency;
    rank rank;
    float voltage;
public:
    CPU(){
        frequency = 5000;
        voltage = 2.1;
        run();
    }
    ~CPU(){
        stop();
    }

    void run(){
        cout<<"CPU开始跑了"<<endl;
    }
    void stop(){
        cout<<"CPU停下来了"<<endl;
    }
};

int main() {
    CPU ThreadRipper;
}