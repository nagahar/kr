#include <stdio.h>

void minprintf(char *, ...);

int main()
{
	int i=48;
	double d=1.03;

	minprintf("%d,%f,%x,%c,%e,%g\n",i,d,i,i,d,d);
	return 0;
}
