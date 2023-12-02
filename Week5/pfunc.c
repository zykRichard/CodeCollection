#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double av[3] = {1112.3, 1542.6, 2227.9};
// trival
double pam(int lns);
double betsy(int lns);
double pam_2(double a);
int pam_3(double a);

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);

double (*pf)(int);
pf = pam;

typedef double (*PF)(int);
PF pf = pam;
PF bf = betsy;
// PF pf2 = pam_2;

typedef const double *(*F)(const double *, int);
F pa[3] = {f1, f2, f3};

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.004 * lns * lns;
}

void estimate(int lines, PF p)
{
    printf("Take in %d lines\n", lines);
    printf("%lf hours\n", (*p)(lines));
}

const double *f1(const double ar[], int n)
{
    return ar;
}

const double *f2(const double *ar, int n)
{
    return ar + 1;
}

const double *f3(const double ar[], int n)
{
    return ar + 2;
}
