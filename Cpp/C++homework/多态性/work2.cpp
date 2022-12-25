#include <iostream>

using namespace std;

class vehicle
{
public:
    void run()
    {
        cout << "vehicle run" << endl;
    }
    void stop()
    {
        cout << "vehicle stop" << endl;
    }
};
class bicycle : public vehicle
{
public:
    void run()
    {
        cout << "bicycle run" << endl;
    }
    void stop()
    {
        cout << "bicycle stop" << endl;
    }
};
class motocar : public vehicle
{
public:
    virtual void run()
    {
        cout << "motocar run" << endl;
    }
    virtual void stop()
    {
        cout << "motocar stop" << endl;
    }
};

int main()
{
    vehicle a;
    motocar b;
    a.run();
    b.run();
}