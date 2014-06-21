#include <stdio.h>

#define MAX_CHAR 2048

void *malloc(unsigned);
void *calloc(unsigned,unsigned);
void free(void *);

static int a[9];
static int b[2];

int main()
{
	char *test,*init;
	int c;
	int i;

	if((test=(char *)malloc(MAX_CHAR))==NULL){
		fprintf(stderr,"size full\n");
		return 0;
	}
	init=test;

	while((c=getchar())!=EOF)
		*test++=(char)c;

	printf("%s\n",init);

	free(test);

	i=0;
	while(i++<8)
		printf("%p\n",&a[i]);

	i=0;
	while(i++<2)
		printf("%p\n",&b[i]);
	printf("%d\n",(int)&a[8]-(int)&b[0]);
	return 0;
}
