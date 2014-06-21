#include <stdio.h>

#define SIZE 100

main()
{
	int n, array[SIZE], getint(int *);

	for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
		printf("array:%d\n",array[n]);
}
