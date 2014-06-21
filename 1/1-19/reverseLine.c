#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char line[]);
void copy(char to[], char from[]);
int length(char s[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
	reverse(line);
	printf("%s",line);
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

void reverse(char line[])
{
    int i,j,num;
    char s[num=length(line)];

    copy(s, line);
    j=0;
    for(i = num-1; i >= 0 ; --i){
	if(s[i]!='\n' && s[i]!='\0'){
	    line[j]=s[i];
	    ++j;
	}
    }
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}

int length(char s[]){
    int i;

    i = 0;
    while (s[i] != '\0')
	++i;
    return i;
}

