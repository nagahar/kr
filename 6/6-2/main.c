#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

char *keytab[] = {
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while",
	NULL	
};


int num;

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int c;
	int iskey(char *);
	int role,hoge,hoho,hoi;
	
	/*
	 * comment
	 */
	printf("test\"");

	while(--argc > 0 && (*++argv)[0]=='-')
		while((c = *++argv[0])!='\0')
			switch(c){
				case 'c':
					num=atoi(++argv[0]);
					*(argv[0]+1)='\0';
					break;
				default:
					printf("Illegal option %c\n",c);
					argc=0;
					return -1;
			}

	root=NULL;
	while(getword(word,MAXWORD)!=EOF){
		printf("word %s\n",word);
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
