#include <iostream>
using namespace std;

class MoveBit{
	public:
		void LogicalMove_left(int n);
		void LogicalMove_right(int n);
		void ArithmeticMove_left(int n);
		void ArithmeticMove_right(int n);
		void LoopMove_left(int n);
		void LoopMove_right(int n);
		void MyPrint(char *s);  //  输出哪一种移位
		void SetData(int n);
	private:
		short int m1;  //原来的数据, 16位 
		short int m2;  //移动后数据，16位 
};

void MoveBit::LogicalMove_left(int n) //左移，右边补0
{	
    m2 = m1 << n;
} 

void MoveBit::LogicalMove_right(int n) //右移，左边补0
{ 
    m2 = m1 >> n;
}

void MoveBit::ArithmeticMove_left(int n) //左移，右边补0 
{	
    m2 = m1 << n;
}

void MoveBit::ArithmeticMove_right(int n) //右移，左边补符号位 
{	
	m2 = m1 >> n;
}

void MoveBit::SetData(int n)
{	
    m1 = n;
}

void MoveBit::LoopMove_left(int n)  
{	
    unsigned short m = m1;
    m2 = (m << n) ^ (m << 16-n);
}
void MoveBit::LoopMove_right(int n)
{ 
    unsigned short m = m1;
    m2 = (m >> n) ^ (m >> 16-n);
}
void MoveBit::MyPrint(char *s)
{	cout<<s<<":"<<endl;  //输出哪一种移位 
	cout<<"m1="<<m1<<endl;
	cout<<"m2="<<m2<<endl;
}

int main()
{	short int k;
    MoveBit test;
	cout<<"sizeof(short int)="<<sizeof(short)<<endl;
    test.SetData(-7);  //  输入-7 
    
    test.LogicalMove_left(2);
    test.MyPrint("LogicalMove_left(2)");
    
    test.LogicalMove_right(2);
    test.MyPrint("LogicalMove_right(2)");
    
    test.ArithmeticMove_left(2);
    test.MyPrint("ArithmeticMove_left(2)");
    
    test.ArithmeticMove_right(2);
    test.MyPrint("ArithmeticMove_right(2)");
    
    test.LoopMove_left(2);
	test.MyPrint("LoopMove_left(2)") ;
	
	test.LoopMove_right(2);
	test.MyPrint("LoopMove_right(2)") ;
}
