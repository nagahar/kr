#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++]=f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}

}

double watch(void)
{
	double d;
	if(sp > 0){
		d=val[sp-1];
		return d;
	}else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void replace(void)
{
	double a,b;
	a=pop();
	b=pop();
	push(a);
	push(b);
}

