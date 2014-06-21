#include "main.h"

int dcl(void);
int dirdcl(void);

int	gettoken(void);
int	tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main()
{
	int type;
	char temp[MAXTOKEN];
	int asterisk=0;

	while(gettoken()!=EOF){
		strcpy(out, token);
		while((type = gettoken())!= '\n'){
			if(type == PARENS || type == BRACKETS){
				if(asterisk){
					sprintf(temp, "(%s)",out);
					strcpy(out,temp);
					asterisk=0;
				}
				strcat(out, token);
			}else if(type == '*'){
				asterisk=1;
				sprintf(temp, "*%s",out);
				strcpy(out,temp);
			}else if(type == NAME){
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}else
				printf("invalid input at %s\n", token);
		}
		printf("%s\n",out);
		asterisk=0;
	}
	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while((c = getch()) == ' ' || c == '\t')
		;
	if(c == '('){
		if((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else if(c == '*' || isalpha(c)){
			ungetch(c);
			return tokentype = '(';
		} else
			return -1;
	}else if(c == '['){
		for(*p++ = c; (*p = getch())!= ']'; p++)
			if(!isdigit(*p)){
				*++p = '\0';
				return -1;
			}
		*++p = '\0';
		return tokentype = BRACKETS;
	}else if(isalpha(c)){
		for(*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}else
		return tokentype = c;
}
