
struct big_thing
{
    char buf[128];
};

struct big_thing return_test()
{
    struct big_thing b;
    b.buf[0] = 0;
    return b;
}

int main()
{
    struct big_thing ret = return_test();
    return 0;
}