#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;

#define SnumPrint(n)          \
    printf("%d ", n.int_val); \
    printf("%ld ", n.l_val);  \
    printf("%lf", n.lf_val)

void demo1();
void demo2();

int main(int argc, char *argv[], char *envp[])
{
    assert(argc > 1);
    if (strcmp("demo1", argv[1]) == 0)
        demo1();
    else if (strcmp("demo2", argv[1]) == 0)
        demo2();
}

// Basic
void demo1()
{
    union Snum
    {
        int int_val;
        ll l_val;
        double lf_val;
    };

    union Snum num;
    scanf("%d", &(num.int_val));
    SnumPrint(num);
    scanf("%ld", &(num.l_val));
    SnumPrint(num);
    scanf("%lf", &(num.lf_val));
    SnumPrint(num);
}

// Anonymous Union
void demo2()
{
    struct widge
    {
        char brand[20];
        int type;
        union
        {
            long id_num;
            char id_char[20];
        };
    };

    // TODO
}
