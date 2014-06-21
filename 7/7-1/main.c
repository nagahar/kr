#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int (*func)(int);
	int c;

	if(argc > 0){
		if(strcmp("upper",argv[0])==0){
			func = toupper;
		}else if(strcmp("lower",argv[0])==0)
			func = tolower;
		else{
			printf("Error argument\n");
			return -1;
		}
	}else{
		printf("Error argument\n");
		return -1;
	}

	putchar((*func)('a'));
	while((c=getchar())!=EOF)
		putchar((*func)(c));

	return 0;

}
