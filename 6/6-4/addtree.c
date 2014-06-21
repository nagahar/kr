#include <stdio.h>
#include "main.h"

struct tnode *talloc(void);
char *strdup(char *);

extern int total;
extern struct tnode *ptree[];

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL){
		p=talloc();
		p->word=strdup(w);
		p->count=1;
		p->left=p->right=NULL;
		ptree[total++]=p;
		printf("new %s\n",p->word);
	}else if((cond=strcmp(w,p->word))==0){
		p->count++;
	}else if(cond < 0){
		p->left=addtree(p->left,w);
	}else{
		p->right=addtree(p->right,w);
	}
	return p;
}
