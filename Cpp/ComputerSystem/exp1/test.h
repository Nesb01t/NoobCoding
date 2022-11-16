#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DecToBin {
public:
 DecToBin();        //构造函数
 void Dec_to_Bin();  //十进制转二进制
 void Bin_to_Dec();  //二进制转十进制
 void Get_Dec();     //得到一个十进制数
 void Prt_Binstr();   //打印三个数：m、Binstr、newm
private:
 double m;
 double newm;
 vector<char> Binstr;
};

DecToBin::DecToBin()
{
 this->m = 0;
 this->newm = 0;
}

void DecToBin::Dec_to_Bin()
{
 int z=int(fabs(m));  //整数部分
 double x = fabs(m) - z;   //小数部分
 int Pre = 6;    //精度
 vector<char> center;
 while (z > 0)     //将m的整数部分二进制的逆序储存到center中
 {
  center.insert(center.end(), char((z % 2) + '0'));
  z /= 2;
  newm++;
 }
 newm--;
 reverse(center.begin(), center.end());     //将原有的二进制逆序正序
 Binstr.insert(Binstr.end(), center.begin(), center.end());
 Binstr.insert(Binstr.end(), '.');
 while (x != 0 && Pre-- > 0)      //将m的小数部分二进制储存到Binstr中
 {
  x *= 2;
  Binstr.insert(Binstr.end(), char(int(x) + '0'));
  x -= int(x);
 }
}

void DecToBin::Bin_to_Dec()
{
 int d = newm;  //位数
 newm = 0;
 int i = 0;
 i = 0;
 /*while (d>-1)    //整数部分计算
 {
  newm += int(Binstr[i]-'0') * pow(2, d);
  d--;
  i++;
 }
 i++;
 d--;
 while (d > -7)       //小数部分计算
 {
  newm += int(Binstr[i]-'0') * pow(2, d);
  d--;
  i++;
 }*/
}

void DecToBin::Get_Dec()
{
 cin >> this->m;
}

void DecToBin::Prt_Binstr()
{
 
 cout << "The Decimal Data m:" << m << endl;
 cout << "The Binary Data m:";
 if (m < 0)
  cout << "-";
 for (auto i : Binstr)
  cout << i;
 cout << endl;
 cout << "The Decimal New Data m:" << newm << endl;
}
