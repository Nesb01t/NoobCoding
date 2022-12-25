class Boat
{
    friend int getTotalWeight(const Boat &boat, const Car &car);

public:
    int weight;
};

class Car
{
    friend int getTotalWeight(const Boat &boat, const Car &car);

public:
    int weight;
};

// 定义一个友元函数，计算两个对象的重量和
int getTotalWeight(const Boat &boat, const Car &car)
{
    return boat.weight + car.weight;
}
int main()
{
    Boat boat;
    boat.weight = 1000;

    Car car;
    car.weight = 2000;

    // 调用友元函数，计算两个对象的重量和
    int totalWeight = getTotalWeight(boat, car);
    std::cout << "Total weight: " << totalWeight << std::endl;
    // 输出：Total weight: 3000
    return 0;
}
