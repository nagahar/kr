#include <stdio.h>

main()
{
	int strend(char *, char *);
	char *s="TEST";
	char *t="EST";
	char *u="HOGE";
	char *v="FUGAFUGA";
	
	printf("%d\n",strend(s,t));
	printf("%d\n",strend(u,v));
}
