#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define ShowStr(str) \
    printf("%s\n", str)

#define Repeat(a, b) \
    for (int i = a; i < b; i++)

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

// string initialization and value assignment
void demo1()
{
    char dog[4] = {'d', 'o', 'g', '\0'};
    // char cat[4] = {'c', 'a', 't', 'd'};
    char cat[4] = {'c', 'a', 't', '\0'};
    ShowStr(dog);
    ShowStr(cat);

    printf("%u\n", cat[4]);
    char name[11] = "Mr.Zhou";
    char __name[] = "Mr.Zhou";
    ShowStr(name);
    ShowStr(__name);

    Repeat(0, 11)
        printf("%c ", name[i]);
}

void demo2()
{
    // RTFM : reading the fxxking manual
    // strcat:

    // strncat:
    // strcmp:
    // strncmp:
    // strchr:
    // strcpy:
    // strncpy:
}



char *mystrcat( char *dest, const char *src ){
    // catenate src to dest
    char *ret = dest;
    while(*dest != '\0')
        dest ++;

    while(*src != '\0'){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
    return ret;
}

