#include <stdio.h>

#define MAX_CHAR 256

void *malloc(unsigned);
void *calloc(unsigned,unsigned);
void free(void *);

int main()
{
	int *test;

	if((test=(int *)calloc(MAX_CHAR,sizeof(int)))==NULL){
		fprintf(stderr,"size full\n");
		return 0;
	}
	
/*	if((test=(int *)malloc(MAX_CHAR))==NULL){
		fprintf(stderr,"size full\n");
		return 0;
	}
	fprintf(stderr,"%d",*test);

	*/
	//fgets(test,MAX_CHAR,stdin);
	*++test=10;
	fprintf(stderr,"%d",*test);

	//printf("%s\n",test);

	free(test);
	return 0;
}
