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
	while(gettoken()!=EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		if(dcl()<0){
			int c,getch(void);
			printf("A syntax error\n");
			while((c = getch()) != '\n')
				;
			continue;
		}
		if(tokentype != '\n'){
			printf("B syntax error\n");
			continue;
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	void strip();

	strip();

	if((c=getch()) == '('){
		strip();
		if((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else if(c == '*' || isalpha(c)){
			ungetch(c);
			return tokentype = '(';
		} else
			return -1;
	}else if(c == '['){
		strip();
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

void strip(void)
{
	int c, getch(void);
	void ungetch(int);
	
	while((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
}
