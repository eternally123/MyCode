

int printf(const char *format, ...);

int global_init_var = 84;
int global_uninit_var;

static int global_static_var = 86;
static int global_static_var2;

void funcl(int i)
{
    printf("%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;

    int a = 1;
    int b;
    funcl(static_var + static_var2 + 1 + b);

    return a;
}

/**
 * gcc -c main.c
 * objdump -h main.o
 **/