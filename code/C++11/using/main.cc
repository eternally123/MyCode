#include <iostream>
#include <memory>

template <typename T>
class Vec
{
public:
    void set(T tmp)
    {
        t = tmp;
    }
    void print()
    {
        std::cout << t << std::endl;
    }

private:
    T t;
};

class InVec
{
    template <typename T>
    using VecPtr = std::shared_prt<Vec<T>>;

public:
    InVec();
    ~InVec();

private:
    VecPtr<int> v;
};

int main()
{

    Vec<int> v;
    v.set(10);
    v.print();
}