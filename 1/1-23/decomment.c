#include <stdio.h>
#define	MAXLEN	1000

int commentflag;/* 1:in-commnet 0:out-comment */
int quoteflag;/* 1:in-quote 0:out-quote */

int getLine(char s[], int len);
void decomment(char s[]);
int size(char s[]);
void copy(char to[], char from[]);
int chstatus(int status);

/*
 * decomment
 */
main()
{
	int len;
	char line[MAXLEN];
	while((len=getLine(line, MAXLEN)>0)){
		decomment(line);
		printf("%s",line);
	}
	printf("%s","hoge \"/*fuga*/\"");
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

void decomment(char s[]){
	int i,j,lim;
	char tmp[lim=size(s)];
	j=0;
	for(i=0; i < lim-1; ++i){
		if(s[i]=='\"'&&(i==0 || s[i-1]!='\\'))
			quoteflag=chstatus(quoteflag);
		if(quoteflag!=1){
			if(commentflag!=1 && s[i]=='/' && s[i+1]=='*')
				commentflag=chstatus(commentflag);
			else if(commentflag==1 && s[i]=='*' && s[i+1]=='/'){
				commentflag=chstatus(commentflag);
				i=i+2;
			}
		}
		if(commentflag!=1){
			tmp[j]=s[i];
			++j;
		}
	}
	tmp[j]='\0';
//	printf("%s\n",tmp);
	copy(s, tmp);
}

int size(char s[]){
	int i;

	for(i = 0; s[i] != '\0' ; ++i);
	return ++i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int chstatus(int status)
{
	if(status==1)
		status=0;
	else
		status=1;
	return status;
}
