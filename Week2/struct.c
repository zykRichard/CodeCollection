#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct inflatable
{
    char name[19];
    float volume;
    double price;
} inflatable;

struct point
{
    int x;
    int y;
};

void demo1();
void demo2();
void demo3();
int main(int argc, char *argv[], char *envp[])
{
    assert(argc > 1);
    if (strcmp("demo1", argv[1]) == 0)
        demo1();
    else if (strcmp("demo2", argv[1]) == 0)
        demo2();
    else if (strcmp("demo3", argv[1]) == 0)
        demo3();
}

// Basis
void demo1()
{
    inflatable guest = {"Glorious Floria", 1.88, 29.99};
    struct inflatable pal = {
        "Audacious Arthur",
        3.12,
        32.99};
    printf("the size of inflatable is %d\n", sizeof(struct inflatable));
    // struct point a = {1, 2};
    char format[] = "For product %s, the volume is %.3f, price is %.4lf\n";
    printf(format, guest.name, guest.volume, guest.price);
    printf(format, pal.name, pal.volume, pal.price);

    guest.volume = 2.0;

    scanf("%f", &(guest.volume));
    printf("%f", guest.volume);
}

// struct array
void demo2()
{
    struct inflatable guest[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99}};

    // How the data is arranged?
}

// bit struct
void demo3()
{
    struct reg
    {
        uint16_t SN : 4;
        uint16_t KN : 4;
        uint8_t goodIN : 1;
        uint8_t goodOUT : 1;
    };
    printf("The size of reg is %u\n", sizeof(struct reg));
    struct reg regs = {10, 10, 1, 0};

    // How these memory arranged?
}

// LinkList
void demo4()
{
    typedef struct LinkList
    {
        int id;
        int val;
        struct LinkList *next;
    } LinkList;
}
