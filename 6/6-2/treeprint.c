#include <stdio.h>
#include <string.h>
#include "main.h"

extern int num;

void treeprint(struct tnode *p)
{
	static char key[MAXWORD];

	if(p != NULL){
		treeprint(p->left);
		if(key==NULL || strncmp(key,p->word,num)!=0){
			int i;
			strncpy(key,p->word,num);
			printf(":");
			for(i=0;i<strlen(p->word) && i<num;i++)
				printf("%c",key[i]);
			printf("\n");
		}
		printf("%4d %s\n",p->count,p->word);
		treeprint(p->right);
	}
}
