class Cat
{
public:
    // 静态数据成员，记录Cat的个体数目
    static int numOfCats;

    // 静态成员函数，读取numOfCats
    static int getNumOfCats() { return numOfCats; }
};

// 初始化静态数据成员
int Cat::numOfCats = 0;

int main()
{
    Cat cat1, cat2;
    // 创建两只猫，numOfCats加2
    Cat::numOfCats += 2;

    std::cout << "Number of cats: " << Cat::getNumOfCats() << std::endl;
    // 输出：Number of cats: 2
    return 0;
}
