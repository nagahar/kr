#include <stdio.h>

#define MAX_CHAR 100

int getLine(char line[], int maxline);
void expand(char s[], char t[]);
void list(char s, char e);

main()
{
	char s[MAX_CHAR];
	char t[26*MAX_CHAR];

	while(getLine(s,MAX_CHAR)>0){
		expand(s,t);
		printf("%s\n",t);
	}
}

void expand(char s[], char t[])
{
	int i,j,k;
	char b,e;
	k=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if(i==0 || s[i-1]>s[i+1])
				t[k++]=s[i];
			else{
				b=s[i-1]+1;
				e=s[i+1];
				for(j=b;j<=e;j++)
					t[k++]=j;
				i++;
			}
		}else
			t[k++]=s[i];
	}
	t[k]='\0';
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
