

class grand
{
public:
    // virtual void g_f(){};
    int g_1;
};

class parent : virtual public grand
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