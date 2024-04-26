// 3_6
#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name_;
    string sex_;
    int age_;
public:
    Person();
    Person(string name,string sex,int age);
    Person(const Person &p);
    ~Person();
    void Print();
};

int main(void)
{
    Person p1;
    Person p2("yzy", "nan", 18);
    Person p3(p2);

    return 0;
}

// Person
Person::Person()
    :name_(""),sex_(""),age_(0) {}

Person::Person(string name, string sex, int age)
    :name_(name),sex_(sex),age_(age) {}

Person::Person(const Person &p)
{
    this->name_ = p.name_;
    this->sex_ = p.sex_;
    this->age_ = p.age_;
}

Person::~Person()
{
    cout << name_ << "OUT!" << endl;
}

void Person::Print()
{
    cout << "name:" << name_ << "sex:" << sex_ << "age:" << age_ << endl;
}