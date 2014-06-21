#include <stdlib.h>
#include "main.h"

int numcmp(struct tnode *s1, struct tnode *s2)
{
	int v1,v2;

	v1=s1->count;
	v2=s2->count;
	if(v1<v2)
		return -1;
	else if(v1>v2)
		return 1;
	else
		return 0;
}
