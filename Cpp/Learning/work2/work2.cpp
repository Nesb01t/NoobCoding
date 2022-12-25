#include <iostream>
using namespace std;
void calc(int mat[3][3])
{
    int i, j, k;
    for(i=0; i<3; i++) {
        for (j=0; j<i; j++) {
            k = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = k;
        }
    }
}
int main()
{
    int i, j;
    int data[3][3];
    cout << "输入矩阵的元素" << endl;
    for(i=0; i<3; i++)
        for (j=0; j<3; j++) {
            cout << "第" << i+1 << "行第" << j+1
                <<"个元素为：";
            cin >> data[i][j];
        }
        cout << "输入的矩阵的为：" << endl;
        for(i=0; i<3; i++) {
            for (j=0; j<3; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
        move(data);
        cout << "转置后的矩阵的为：" << endl;
        for(i=0; i<3; i++) {
            for (j=0; j<3; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    return 0;
}