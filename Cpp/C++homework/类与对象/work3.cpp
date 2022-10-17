#include <iostream>
#include <Date.h>

using namespace std;

class People {
private:
    int number, sex, id;
    DateBirth birthday;
public:
    People(){

    }
    People(const People &p){
        this.number = p.number;
        this.sex = p.sex;
        this.id = p.id;
        this.birthday = p.birthday;
    }
    
    void setBirthday(int y, int m, int d){
        birthday.SetDateBirth(y, m, d);
    }
    void setSex(int n){this.sex = n};
    void setNumber(int n){this.number = n};
    void setId(int n){this.id = n};
};

class DateBirth {
private:
    int year, month, day;
public:
    Birth() {};
    ~Birth() {};
    void SetDateBirth(int year, int month, int day){
        this.year = year;
        this.month = mont;
        this.day = day;
    }
}
int main() {
    People p;
}