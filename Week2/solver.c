#include <stdio.h>
#include <math.h>

double esp = 1e-6;

double f(double a, double b);

double solver(double a, double b){
	double mid = (a + b) / 2;
	double flag = f(mid);
	if(fabs(flag) <= esp)
		return mid;

	if(flag > 0)
		return solver(a, flag);
	else return solver(flag, b);

}
