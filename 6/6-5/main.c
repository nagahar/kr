#include <stdio.h>
#include "main.h"

struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

int main()
{
	struct nlist *np;
	char *s="IN";


	install(s,"10");
	if((np=lookup(s))!=NULL)
		printf("%s:%s\n",np->name,np->defn);
	undef(s);
	if((np=lookup(s))==NULL)
		printf("UNDEF\n");
	install(s,"20");
	if((np=lookup(s))!=NULL)
		printf("%s:%s\n",np->name,np->defn);
	
	return 0;
}
