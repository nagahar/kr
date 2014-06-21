#include <stdio.h>

void minscanf(char *, ...);

int main()
{
	int i=0;
	float d=0,e;
	char s[100];
	char c;

	printf("%d,%f\n",i,d);
	minscanf("%d%f%s%c%e",&i,&d,s,&c,&e);
	printf("%d,%f,%s,%c,%e\n",i,d,s,c,e);
	return 0;
}
