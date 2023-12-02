#include <stdio.h>

void funcb(int a,int b);

void funca(){
	funcb(1, 2);
	return;
}

int main(){
	funca();
	return 0;
}
