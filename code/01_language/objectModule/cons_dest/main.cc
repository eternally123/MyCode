class A
{
public:
    virtual ~A(){};
    int a;
};

class B : virtual public A
{
public:
    virtual ~B(){};
    int b;
};

class C : virtual public A
{
public:
    virtual ~C(){};
    int c;
};

class D : public B, public C
{
public:
    virtual ~D(){};
    int d;
};

int main()
{
    D *d = new D();
    delete d;
}