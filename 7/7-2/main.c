#include <stdio.h>

int main()
{
	int c;
	int count=0;
	while((c=getchar())!=EOF){
		if(count++==20){
			printf("\n");
			count=0;
		}
		if(0x21 <= c && c <= 0x7e)
			printf("%c",c);
		else
			printf("0x%02x",c);
	}
	printf("\n");

}
