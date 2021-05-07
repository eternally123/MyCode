

class grand
{
public:
    int g_1;
};

class parent : public grand
{
public:
    virtual ~parent(){};
    int p_1;
};

int main()
{
    parent p;
    grand *g = (grand *)(&p);
    return 0;
}