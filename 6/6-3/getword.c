#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w=word;

	while(isspace(c=getch())){
		if(c=='\n'){
			*w++=c;
			*w='\0';
			return c;
		}
	}
	if(c!=EOF)
		*w++=c;
	/*if(c=='\''){
		while((*w++=getch())!='\''||(*(w-2)=='\\'&&*(w-3)!='\\'))
			;
		*w='\0';
		return c;
	}else if(c=='/'){
		if((*w++=getch())=='*'){
			while(--lim>0 &&((*w++=getch())!='/' || *(w-2)!='*'))
				;
			*w='\0';
			return c;
		}else
			ungetch(*--w);
	}else if(c=='#'){
		while(--lim>0 && (*w++=getch())!='\n')
			;
		ungetch(*--w);
		*w='\0';
		return c;
	}else if(c=='"'){
		while((*w++=getch())!='"' || (*(w-2)=='\\' && *(w-3)!='\\'))
			;
		*w='\0';
		return c;
	}*/
	if(!isalpha(c)){
		*w='\0';
		return c;
	}
	for(;--lim>0;w++)
		if(!isalnum(*w=getch())&&*w!='\''){
			ungetch(*w);
			break;
		}
	*w='\0';
	return word[0];
}
