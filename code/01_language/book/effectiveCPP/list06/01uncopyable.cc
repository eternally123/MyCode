#include "uncopyable.hh"

class people : public uncopyable
{
public:
    people() {}
    virtual ~people() {}
};

int main()
{
    people p;
    // people q(p);
}