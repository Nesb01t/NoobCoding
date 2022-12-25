#include <iostream>
#include <string>

// 异常抽象类
class Exception
{
public:
    virtual ~Exception() = default;
    virtual const char *what() const = 0;
};

// OutOfMemory类，响应内存不足
class OutOfMemory : public Exception
{
public:
    OutOfMemory(const std::string &message) : message_(message) {}
    virtual const char *what() const { return message_.c_str(); }

private:
    std::string message_;
};

// RangeError类，响应输入的数不在指定范围内
class RangeError : public Exception
{
public:
    RangeError(const std::string &message) : message_(message) {}
    virtual const char *what() const { return message_.c_str(); }

private:
    std::string message_;
};

int main()
{
    try
    {
        throw OutOfMemory("Out of memory error");
    }
    catch (const Exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        throw RangeError("Input number out of range");
    }
    catch (const Exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}