#include <iostream>
using namespace std;

#pragma pack(1)
class Grand
{
public:
    virtual ~Grand() {}
};

class Base1 : public Grand
{
public:
    virtual ~Base1() {}
};

class Base2 : public Grand
{
public:
    virtual ~Base2() {}
};

class Base3 : public Grand
{
public:
    virtual ~Base3() {}
};

class Base4 : public Grand
{
public:
    virtual ~Base4() {}
};

class Derived : public Base1, public Base2, public Base3, public Base4
{
public:
    virtual ~Derived() {}
};

#pragma pack()

int main()
{
    cout << sizeof(Grand) << endl;
    cout << sizeof(Base1) << endl;
    cout << sizeof(Base2) << endl;
    cout << sizeof(Derived) << endl;
}