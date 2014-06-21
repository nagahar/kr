#include <stdio.h>
#include <string.h>
#include "main.h"

extern int num;

void treeprint(struct tnode *p)
{
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n",p->count,p->word);
		treeprint(p->right);
	}
}
