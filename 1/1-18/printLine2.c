#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void deleteBlank(char line[], int num);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > 0){
		if(len > 1){
			if(line[len-1] == '\n'){
				deleteBlank(line,len);
			}
			printf("%s",line);
		}
	}
	return 0;
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

void deleteBlank(char line[], int num)
{
	int i;
	for(i = num; i >= 0 && (line[i]=='\t' || line[i]==' ' || line[i]=='\0' || line[i]=='\n'); --i){
		line[i]='\0';
	}
	line[i+1]='\n';
}
