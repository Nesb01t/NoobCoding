#include "hzCount.h"

using namespace std;

void HzGenerator(); // 汉字表生成器

int main()
{
    HzGenerator();
    
    HzCount hzCount;
    hzCount.getFilename();
    hzCount.sortHz();
    hzCount.printHzTable();
    return 0;
}

void HzGenerator()
{ 
    int i, j;
    unsigned char c[3];
    c[2] = '\0';
    freopen("outTable.txt", "w", stdout);
    for (size_t i = 1; i <= 126; i++)
    {
        c[0] = i + 0x80;
        for (size_t j = 0; j <= 125; j++)
        {
            c[1] = j + 0x80;
            cout << c << '\t';
        }
        cout << endl;
    }
}