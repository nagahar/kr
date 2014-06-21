#include <stdio.h>

int getline(char *s, int lim)
{
	int c;
	char *tmp=s;

	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s = '\0';
	return s-tmp;
}
