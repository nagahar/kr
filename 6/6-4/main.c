#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int numcmp(struct tnode *, struct tnode *);
void qsort(void *[], int , int , int (*)(void *, void *));

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

int total;
struct tnode *ptree[MAXNODE];

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int iskey(char *);
	void writelines(struct tnode *[],int);

	root=NULL;
	while(getword(word,MAXWORD)!=EOF){
		printf("word %s\n",word);
		if(!iskey(word) && (isalpha(word[0]) || word[0]=='_'))
			root=addtree(root,word);
	}

	qsort((void **)ptree,0,total-1,(int (*)(void *, void *))numcmp);
	writelines(ptree,total);
	//treeprint(root);
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

void writelines(struct tnode *lineptr[], int nlines)
{
	while(nlines-->0)
		printf("%4d %s\n",lineptr[nlines]->count,lineptr[nlines]->word);
}
