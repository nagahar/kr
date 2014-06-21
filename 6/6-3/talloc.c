#include <stdlib.h>
#include "main.h"

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct rowlist *rowalloc(void)
{
	return (struct rowlist *)malloc(sizeof(struct rowlist));
}

char *strdup(char *s)
{
	char *p;

	p=(char *)malloc(strlen(s)+1);
	if(p!=NULL)
		strcpy(p,s);
	return p;
}
