#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c, tmp;
	static int ch;
	i=0;
	//	fprintf(stderr,"getopstart\n",s);
	//printf("%d\n",ch);
	if(ch > 0 && ch != ' ' && ch != '\t')
		s[0]=ch;
	else
		while((s[0]=c=getch())==' ' || c=='\t')
			;
	s[1]='\0';
	//	fprintf(stderr,"s:%s\n",s);
	if(c == '-') {
		if(isdigit(tmp=getch())){
			/* negative number */
			s[++i]=c=tmp;
		}else{
			/* negative operator */
			ch = c;
			//ungetch(tmp);
			return c;
		}
	}else{
		if(!isdigit(c) && c != '.'){
			/* operator */
			// printf("c:%d\n",c);
			return c;
		}
	}
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	if(c == '.')
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	ch = c;
//	if(c != EOF)
//		ungetch(c);
	return NUMBER;
}
