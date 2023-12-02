#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long ll;

#define SnumPrint(n)          \
    printf("%d ", n.int_val); \
    printf("%lld ", n.l_val); \
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
    printf("sizeof Snum is %u\n", sizeof(num));
    memset(&num, 0, 8);
    SnumPrint(num);
    scanf("%d", &(num.int_val));
    SnumPrint(num);
    scanf("%lld", &(num.l_val));
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
        // int s;
    };
    struct widge w;

    // TODO
}

// union instruction
// {
//    uint32_t num;
//    struct instructop{
//     uint8_t op : 6;
//     uint8_t reg1 : 5;
//     uint8_t reg2: 5;
//     uint8_t reg3 : 5;
//     uint32_t others : 11
//    };
// };
