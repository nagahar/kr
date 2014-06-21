#include <string.h>

void reverse(char s[])
{
	static int i;
	char c;

	c=s[i++];
	if(i < strlen(s))
		reverse(s);
	s[strlen(s)-i]=c;
	i--;
}
