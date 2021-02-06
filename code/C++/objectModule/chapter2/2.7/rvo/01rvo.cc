#include <iostream>
using namespace std;
class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator)
    {
        cout << "Constructor Called..." << endl;
    }
    ~Rational()
    {
        cout << "Destructor Called..." << endl;
    }
    Rational(const Rational &rhs)
    {
        this->d = rhs.d;
        this->n = rhs.n;
        cout << "Copy Constructor Called..." << endl;
    }
    int numerator() const { return n; }
    int denominator() const { return d; }

private:
    int n, d;
};
const Rational operator*(const Rational &lhs, const Rational &rhs)
{
    cout << "----------- Enter operator* -----------" << endl;
    Rational tmp(lhs.numerator() * rhs.numerator(),
                 lhs.denominator() * rhs.denominator());
    cout << "----------- Leave operator* -----------" << endl;
    return tmp;
}
int main(int argc, char **argv)
{
    Rational x(1, 5), y(2, 9);
    Rational z = x * y;
    cout << "calc result: " << z.numerator()
         << "/" << z.denominator() << endl;

    return 0;
}

/**
 * 目前版本编译器默认为：直接在返回值上构造对象，所以这个示例中没有拷贝构造函数调用
 * gcc9.3 g++9.3
 * 
 * 默认情况下的输出：
 * Constructor Called...
 * Constructor Called...
 * ----------- Enter operator* -----------
 * Constructor Called...
 * ----------- Leave operator* -----------
 * calc result: 2/45
 * Destructor Called...
 * Destructor Called...
 * Destructor Called...

 * 
 * 当关闭优化时：
 * ~/user/code/MyCode/code/C++/objectModule/chapter2/2.7/rvo(master*) » g++ -fno-elide-constructors main.cc  
 * ~/user/code/MyCode/code/C++/objectModule/chapter2/2.7/rvo(master*) » ./a.out
 * Constructor Called...
 * Constructor Called...
 * ----------- Enter operator* -----------
 * Constructor Called...
 * ----------- Leave operator* -----------
 * Copy Constructor Called...  // 函数返回值临时对象构造
 * Destructor Called...        // 函数内tmp对象析构
 * Copy Constructor Called...  // z构造时调用拷贝构造
 * Destructor Called...        // 函数返回值临时对象析构
 * calc result: 2/45
 * Destructor Called...
 * Destructor Called...
 * Destructor Called...
 * 
 * 可以看到，关闭返回值优化，会产生返回值临时对象。
 * 同时还会产生一个调用函数体内的对象构造。
 * 
 * 即返回值优化可以直接将函数内对象构造到返回值上，甚至于构造到调用函数的代码块中。***
 * 
 * 
 * 思考：是否没必要注意减少临时对象构造的资源浪费？因为编译器都已经优化的很好了。
 * 多线程环境下是否还能优化这么好？
 **/