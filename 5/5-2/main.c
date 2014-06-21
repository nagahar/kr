#include <stdio.h>

#define SIZE 100

main()
{
	int n,getfloat(float *);
	float array[SIZE]; 

	for(n=0;n<SIZE && getfloat(&array[n])!=EOF;n++)
		printf("array:%g\n",array[n]);
}
