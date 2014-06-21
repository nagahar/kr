#include <stdio.h>

int lower(int c);

main()
{
	int c='C';
	printf("%c\n",c);
	printf("%c\n",lower(c));
	return 0;
}

int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

