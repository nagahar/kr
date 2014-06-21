#include <stdio.h>

#define MAX_CHAR 2048

void *malloc(unsigned);
void *calloc(unsigned,unsigned);
void free(void *);
void bfree(void *, unsigned);

static char st[10];

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

	for(i=0;i<10;i++){
		st[i]=i;
		printf("%d",st[i]);
	}
	printf("\n");

	bfree(st,10);
	for(i=0;i<10;i++){
		printf("%d ",st[i]);
	}
	printf("\n");

	free(test);
	return 0;
}
