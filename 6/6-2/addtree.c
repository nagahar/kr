#include <stdio.h>
#include "main.h"

struct tnode *talloc(void);
char *strdup(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL){
		p=talloc();
		p->word=strdup(w);
		p->count=1;
		p->left=p->right=NULL;
		printf("new %s\n",p->word);
	}else if((cond=strcmp(w,p->word))==0){
		p->count++;
		printf("count %d, %s == %s\n",p->count,w,p->word);
	}else if(cond < 0){
		p->left=addtree(p->left,w);
		printf("next left %s\n",p->word);
	}else{
		p->right=addtree(p->right,w);
		printf("next right %s\n",p->word);
	}
	return p;
}
