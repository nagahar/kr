#include <stdio.h>

int isupper(int);

int main()
{
	int c;
	while((c=getchar())!=EOF){
		putchar(c);
		if(isupper(c))
			printf(" is upper\n");
		else
			printf(" is not upper\n");
	}
	return 0;
}
