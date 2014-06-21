#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

char *keytab[] = {
	"the",
	"a",
	"and",
	"or",
	"to",
	"on",
	"not",
	"from",
	NULL
};

int row=1;

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int iskey(char *);
	int role,hoge,hoho,hoi;

	/*
	 * comment
	 */
	printf("test\n");

	root=NULL;
	while(getword(word,MAXWORD)!=EOF){
		printf("word %s\n",word);
		if(word[0]=='\n')
			row++;
		if(!iskey(word) && (isalpha(word[0]) || word[0]=='_'))
			root=addtree(root,word);
	}
	treeprint(root);
	return 0;
}

int iskey(char *word)
{
	int i=0,keylen(char *[]);
	for(i=0;i<keylen(keytab);i++){
		if(strcmp(keytab[i],word)==0)	
			return 1;
	}
	return 0;
}

int keylen(char *key[])
{
	int i=0;
	while(key[i++]!=NULL)
		;
	return i-1;
}
