

class grand
{
public:
    virtual void g_f(){};
    int g_1;
};

class grand2
{
public:
    virtual void g2_f(){};
    int g2_1;
};
class parent : public grand, public grand2
{
public:
    virtual void p_f(){};
    int p_1;
};

int main()
{
    parent p;
    grand *g = (grand *)(&p);
    return 0;
}