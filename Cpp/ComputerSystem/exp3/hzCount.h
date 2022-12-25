#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct HzElem //记录汉字本身、出现次数
{
    unsigned char hz[3];
    int num;
    int type;
};

enum ChType
{
    CN_CHARACTER = 0, // 中文字符
    CN_SYMBOL = 1,    // 中文符号
    EN_CHARACTER = 2, // 西文字符
};

class HzCount
{
public:
    HzCount();                                           //* 构造函数
    ~HzCount();                                          //* 析构函数
    void getFilename();                                  //* 得到一个文件名，并判断文件打开是否正常？
    void getHz();                                        //* 得到一个汉字 ，并进行统计
    void printHzTable();                                 //* 打印 HzTable的数据
    void sortHz();                                       //* 汉字GB2312排列顺序
    int find(vector<struct HzElem>, unsigned char hz[]); //* 判断汉字是否存在表中

    bool static _compare(const HzElem &, const HzElem &); //* 比较函数
private:
    char filename[120]; //需要统计的文件名
    ifstream inFile;
    vector<struct HzElem> hzTable; //存放汉字、数量
};

/**
 * 构造&析构
 */
HzCount::HzCount()
{
    memset(filename, '\0', sizeof(filename));
}
HzCount::~HzCount()
{
    inFile.close();
}

// 读取文件
void HzCount::getFilename()
{
    cin >> filename;
    inFile.open(filename, ios_base::in);
    if (!inFile.is_open())
    {
        cout << "open failed!" << endl;
    }
    else
    {
        cout << "open success!" << endl;
    }
    while (!inFile.eof())
    {
        getHz();
    }
}

// 读1个汉字
void HzCount::getHz()
{
    // 初始化汉字 char
    unsigned char c[3];

    c[0] = inFile.get();
    if (c[0] < 0x81 || (int)(c[0]) >= 255)
        return;

    c[1] = inFile.get();
    if (c[1] < 0x80 || (int)(c[1]) >= 255)
        return;

    c[2] = '\0';

    // 查找下标
    int index = find(hzTable, c);
    if (index == -1) // 未找到
    {
        struct HzElem hzElem;
        memcpy(hzElem.hz, c, sizeof(c));
        hzElem.num = 1;
        hzElem.hz[0] > 0x80 + 33 && hzElem.hz[0] < 0x80 + 41 ? hzElem.type = CN_SYMBOL : hzElem.type = CN_CHARACTER;

        hzTable.push_back(hzElem);
    }
    else
    {
        hzTable[index].num++;
    }
}

// 表格打印
void HzCount::printHzTable()
{
    freopen("output.txt", "w", stdout);
    for (size_t i = 0; i < hzTable.size(); i++)
    {
        hzTable[i].type == CN_CHARACTER ? cout << "CHAR\t" : cout << "SIGN\t";
        cout << hzTable[i].hz << '\t' << hzTable[i].num << endl;
    }
}

// 排序
void HzCount::sortHz()
{
    sort(hzTable.begin(), hzTable.end(), _compare);
}

// 查找汉字元素
int HzCount::find(vector<struct HzElem> table, unsigned char hz[])
{
    for (size_t i = 0; i < table.size(); i++)
    {
        if (table[i].hz[1] == hz[1] && table[i].hz[2] == hz[2])
        {
            return i;
        }
    }
    return -1;
}

// 排序比较函数
bool HzCount::_compare(const HzElem &a, const HzElem &b)
{
    if (a.hz[0] < b.hz[0])
    {
        return true;
    }
    else
    {
        return a.hz[1] < b.hz[1];
    }
}