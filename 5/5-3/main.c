#include <stdio.h>

main()
{
	void strcat(char *, char *);
	char s[]="TEST";
	char *t="DESU";
	strcat(s,t);
	printf("%s\n",s);
}
