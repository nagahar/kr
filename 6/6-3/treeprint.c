#include <stdio.h>
#include <string.h>
#include "main.h"

extern int num;

void treeprint(struct tnode *p)
{

	if(p != NULL){
		int i;
		struct rowlist *r;
		treeprint(p->left);
		printf("%4d %s\n",p->count,p->word);
		for(r=p->begin,i=0;i<p->count;r=r->next,i++)
			printf("\t%4d\n",r->row);
		treeprint(p->right);
	}
}
