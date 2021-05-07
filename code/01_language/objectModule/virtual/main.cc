#include <stdio.h>

class grand
{
public:
    double g_1;
};

class parent : virtual public grand
{
public:
    double p1_1;
};

int main()
{
    parent p;
    return 0;
}