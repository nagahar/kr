#include <string.h>

void reverse(char *s)
{
	char *c,tmp;

	for(c=s+strlen(s)-1; s < c ;s++, c--){
		tmp=*s;	
		*s=*c;
		*c=tmp;
	}
}
