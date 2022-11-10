
#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date(int y = 2000, int m = 1, int d = 1);
    int getYear();
    int getMonth();
    int getDay();
    void input();
    void show();

private:
    int year, month, day;
};

class People
{
public:
    People(int number, char sex, Date birthday, string id);
    People(){};
    ~People();
    People(People &p);
    void input();
    void show();
    int getNumber();
    char getSex();
    Date getBirthday();
    string getID();

private:
    int number;
    char sex;
    Date birthday;
    string id;
};

class Teacher : virtual public People
{
public:
    Teacher(int number, char sex, Date birthday, string id, char *principalship, char *department);
    Teacher(){};
    char *getPrincipalship();
    char *getDepartment();
    void input();
    void show();

protected:
    char principalship[11];
    char department[21];
};

class Student : virtual public People
{
public:
    Student(int number, char sex, Date birthday, string id, char *classNO);
    Student(){};
    char *getClassNO();
    void input();
    void show();

protected:
    char classNO[7];
};

class Graduate : public Student
{
public:
    Graduate(int number, char sex, Date birthday, string id, char *classNO, char *subject, Teacher adviser);
    Graduate(){};
    char *getSubject();
    Teacher &getAdviser();
    void input();
    void show();

protected:
    char subject[21];
    Teacher adviser;
};

class TA : virtual public Graduate, virtual public Teacher
{
public:
    TA(){}; //同上方式进行继承
};

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date(int y = 2000, int m = 1, int d = 1);
    int getYear();
    int getMonth();
    int getDay();
    void input();
    void show();

private:
    int year, month, day;
};

class People
{
public:
    People(int number, char sex, Date birthday, string id);
    People(){};
    ~People();
    People(People &p);
    void input();
    void show();
    int getNumber();
    char getSex();
    Date getBirthday();
    string getID();

private:
    int number;
    char sex;
    Date birthday;
    string id;
};

class Teacher : virtual public People
{
public:
    Teacher(int number, char sex, Date birthday, string id, char *principalship, char *department);
    Teacher(){};
    char *getPrincipalship();
    char *getDepartment();
    void input();
    void show();

protected:
    char principalship[11];
    char department[21];
};

class Student : virtual public People
{
public:
    Student(int number, char sex, Date birthday, string id, char *classNO);
    Student(){};
    char *getClassNO();
    void input();
    void show();

protected:
    char classNO[7];
};

class Graduate : public Student
{
public:
    Graduate(int number, char sex, Date birthday, string id, char *classNO, char *subject, Teacher adviser);
    Graduate(){};
    char *getSubject();
    Teacher &getAdviser();
    void input();
    void show();

protected:
    char subject[21];
    Teacher adviser;
};

class TA : virtual public Graduate, virtual public Teacher
{
public:
    TA(){}; //同上方式进行继承
};