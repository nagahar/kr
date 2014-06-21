#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256
void reverse(char s[]);

main()
{
	char s[MAX_CHAR]="test name";

	printf("%s\n",s);
	reverse(s);
	printf("%s\n",s);
}
