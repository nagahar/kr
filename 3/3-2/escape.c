#include <stdio.h>

#define MAX_CHAR 100

int getLine(char line[], int maxline);
void escape(char s[], char t[]);
void invEscape(char s[], char t[]);

main()
{
	char s[MAX_CHAR];
	char t[2*MAX_CHAR];

	while(getLine(s,MAX_CHAR)>0){
		escape(s,t);
		printf("%s\n",t);
		invEscape(s,t);
		printf("%s\n",t);
	}
}

void escape(char s[], char t[])
{
	int i=0;
	int j=0;
	while(s[i]!='\0'){	
		switch (s[i]){
			case '\n':
				t[j++]='\\';
				t[j++]='n';
				break;
			case '\t':
				t[j++]='\\';
				t[j++]='t';
				break;
			default:
				t[j++]=s[i];
				break;
		}
		i++;
	}
	t[j]='\0';
}

void invEscape(char s[], char t[])
{
	int i=0;
	int j=0;
	int flag=0;
	while(s[i]!='\0'){	
		switch (s[i]){
			case '\\':
				if(s[i+1]=='n'){
					t[j++]='\n';
					i++;
				}else if(s[i+1]=='t'){
					t[j++]='\t';
					i++;
				}else
					t[j++]=s[i];
				break;
			default:
				t[j++]=s[i];
				break;
		}
		i++;
	}
	t[j]='\0';
}

int getLine(char s[], int lim)
{
	int c, i;

	for(i =0; i<lim-1 && (c=getchar())!=EOF && c!='\n' ; ++i){
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;    
	}
	s[i] = '\0';
	return i;
}
