#include <iostream>
#include <cstring> // 包含strlen函数
#include <string>

// 用字符数组实现的函数
int countLetters(const char *str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        { // 判断是否为字母
            count++;
        }
    }
    return count;
}

// 用string类实现的函数
int countLetters(const std::string &str)
{
    int count = 0;
    for (char c : str)
    {
        if (isalpha(c))
        { // 判断是否为字母
            count++;
        }
    }
    return count;
}

int main()
{
    // 使用字符数组实现
    char str1[] = "Hello, World!";
    std::cout << "Number of letters in \"" << str1 << "\": " << countLetters(str1) << std::endl;

    // 使用string类实现
    std::string str2 = "Hello, World!";
    std::cout << "Number of letters in \"" << str2 << "\": " << countLetters(str2) << std::endl;

    return 0;
}
