#include <stdio.h>

int main()
{
	int n;
	while((n=getc(stdin))!=EOF){
		printf("test\n");
		putc(n,stdout);
		printf("test\n");
		fflush(stdout);
	}
	fflush(stdout);
	printf("test\n");
	fflush(stdout);
	printf("test\n");
return 0;
}
