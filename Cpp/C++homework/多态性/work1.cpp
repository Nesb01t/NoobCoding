#include <iostream>

using namespace std;

class Point
{
public:
    Point()
    {
        _x = 0;
        _y = 0;
    }
    Point(int x, int y)
    {
        this->_x = x;
        this->_y = y;
    }
    void log()
    {
        cout << "当前坐标为: (" << _x << ", " << _y << ")" << endl;
    }
    Point operator++()
    {
        _x++;
        _y++;
        return Point(_x, _y);
    }
    Point operator--()
    {
        _x--;
        _y--;
        return Point(_x, _y);
    }
private:
    int _x;
    int _y;
};

int main()
{
    Point a;
    Point b = a++;
    a.log();
}