#include "main.h"

extern char out[];
extern int gettoken(void);
extern int tokentype;
extern char name[];
extern char token[];

int dcl(void);
int dirdcl(void);

int dcl(void)
{
	int ns;
	int c;

	for(ns = 0; (c=gettoken()) == '*'; )
		ns++;
	if(c<0 || dirdcl()<0)
		return -1;
	while(ns-- > 0)
		strcat(out, " pointer to");
	return 0;
}

int dirdcl(void)
{
	int type;
	char temp[MAXTOKEN];

	if(tokentype == '('){
		if(dcl()<0)
			return -1;
		if(tokentype != ')'){
			printf("error: missing )\n");
			return -1;
		}
	}else if(tokentype == NAME)
		strcpy(name, token);
	else{
		printf("error: expected name or (dcl)\n");
		return -1;
	}

	while((type = gettoken()) == PARENS || type == BRACKETS)
		if(type == PARENS){
			sprintf(temp, "function %s returning",token);
			strcat(out, temp);
		}else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	if(type<0) return type;
	return 0;
}
