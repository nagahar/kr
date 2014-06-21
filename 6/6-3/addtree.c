#include <stdio.h>
#include "main.h"

struct tnode *talloc(void);
struct rowlist *rowalloc(void);
char *strdup(char *);

extern int row;

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL){
		p=talloc();
		p->word=strdup(w);
		p->count=1;
		p->left=p->right=NULL;
		p->begin=p->last=rowalloc();
		p->begin->row=row;
		printf("new %s %d\n",p->word,row);
	}else if((cond=strcmp(w,p->word))==0){
		struct rowlist *r=rowalloc();
		p->count++;
		p->last->next=r;
		p->last=r;
		p->last->row=row;
		printf("count %d, %d\n",p->count,row);
	}else if(cond < 0){
		p->left=addtree(p->left,w);
	}else{
		p->right=addtree(p->right,w);
	}
	return p;
}
