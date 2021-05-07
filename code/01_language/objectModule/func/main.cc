

class A
{
public:
    virtual void f_a() { int i = 0; }
};

int main()
{
    A a;
    a.f_a();
    A *pa = new A();
    pa->f_a();
    delete pa;
}