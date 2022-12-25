#include <iostream>
#include <fstream> // fstream头文件

int main()
{
    // 以文本方式建立一个文件test.txt
    std::ofstream file("test.txt");
    // 写入字符"已成功写入文件！"
    file << "已成功写入文件！" << std::endl;
    file.close();

    // 以文本方式打开该文件
    std::fstream file2("test.txt", std::ios::in | std::ios::out | std::ios::app);
    // 在文件后面添加字符"已成功添加字符！"
    file2 << "已成功添加字符！" << std::endl;

    // 读出整个文件内容
    std::string line;
    while (getline(file2, line))
    {
        std::cout << line << std::endl;
    }

    file2.close();
    return 0;
}
