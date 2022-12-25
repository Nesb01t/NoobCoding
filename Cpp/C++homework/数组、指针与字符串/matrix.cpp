#include <iostream>

// 定义矩阵类型
typedef int Matrix[3][3];

// 实现3x3矩阵转置的函数
void transpose(Matrix matrix)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    // 输入3x3矩阵
    Matrix matrix;
    std::cout << "Enter a 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    // 输出转置后的矩阵
    transpose(matrix);
    std::cout << "Transposed matrix:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
