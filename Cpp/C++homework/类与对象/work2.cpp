#include <iostream>
#include <String>

using namespace std;

class Computer {
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
public:
    Computer(){
        run();
    }
    ~Computer(){
        stop();
    }

    void run(){
        cout<<"电脑跑起来了"<<endl;
    }
    void stop(){
        cout<<"电脑停下来了"<<endl;
    }
};

class CPU {};
class RAM {};
class CDROM {};

int main() {
    CPU ThreadRipper;
}