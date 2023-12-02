#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

// basic
void demo1()
{
    enum spectrum
    {
        red,
        orange,
        yellow,
        green,
        blue,
        violet,
        indigo,
        ultraviolet
    };

    enum spectrum band;

    band = blue;
    assert(band == 4);
    // band = 2000;

    band = orange;
    ++band; // yellow
    assert(band == yellow);
    band = orange + red; // orange
    assert(band == orange);
    band = ultraviolet / orange;
    printf("%d\n", band);
    int color = 3;
    band = 3;
    color = 3 + red;
}

// modify init
void demo2()
{
    enum bits
    {
        one = 1,
        two = 2,
        four = 4,
        eight = 8
    };
    enum bigstep
    {
        first,
        second = 100,
        third
    };
    enum strange
    {
        zero,
        null = -2,
        ones,
        numer_uno = -300,
        test
    };
}

// input : int n ; int a[n]:
// a[i] = 999 : 在这个枚举中第i个属性没赋值
// a[i] = other: 在这个枚举中第i个属性赋值为 other

// outputs : n 个枚举属性的值
