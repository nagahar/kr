#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

#define MAXWORD 100

struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
int getword(char *, int);
void gettuple(char *,struct pair *); 

char word[MAXWORD];
int main()
{
	struct nlist *np;
	struct pair p;
	char *def="#define";

	while(getword(word,MAXWORD)!=EOF){
		printf("word %s\n",word);
		if(strncmp(word,def,strlen(def))==0){
			gettuple(word,&p);	
			np=install(p.name,p.val);
			printf("%s:%s\n",np->name,np->defn);
			if((np=lookup(p.name))!=NULL)
				printf("%s:%s\n",np->name,np->defn);
		}
	}

	return 0;
}

void gettuple(char *word,struct pair *p)
{
	char *w=word;
	char *tmp;

	while(!isspace(*w))
		w++;
	while(isspace(*w))
		w++;
	*(w-1)='\0';
	tmp=w;
	while(isalnum(*w)||*w=='_')
		w++;
	*w++='\0';
	p->name=tmp;
	while(isspace(*w))
		w++;
	p->val=w;
}
