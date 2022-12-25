#include <iostream>
#include <fstream> // fstream头文件

int main()
{
    // 打开指定的文本文件
    std::ifstream inputFile("input.txt");
    // 在每一行前加行号后将其输出到另一个文本文件中
    std::ofstream outputFile("output.txt");

    std::string line;
    int lineNumber = 1;
    while (getline(inputFile, line))
    {
        outputFile << lineNumber << ": " << line << std::endl;
        lineNumber++;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
