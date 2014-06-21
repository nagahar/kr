#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256
int itoa(int n, char s[]);

main()
{
	int n=100;
	char s[MAX_CHAR];

	printf("%d\n",n);
	itoa(n,s);
	printf("%s\n",s);
}
