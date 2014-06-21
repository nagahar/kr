#include <stdio.h>
#define	MAXLEN	1000
#define	STACKLEN	100

int commentflag;/* 1:in-commnet 0:out-comment */
int dquoteflag;/* 1:in-quote 0:out-quote */
int squoteflag;/* 1:in-quote 0:out-quote */
int stack[STACKLEN];
int last;

int getLine(char s[], int len);
void check(char s[]);
int size(char s[]);
void copy(char to[], char from[]);
int chstatus(int status);
int push(int c);
void pop(void);

/*
 * syntax check
 */
main()
{
	int len;
	char line[MAXLEN];
	while((len=getLine(line, MAXLEN)>0)){
		check(line);
	}
	if(last>0)
		printf("syntax error\n");
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

void check(char s[]){
	int i;
//	int j;
	for(i=0; i < size(s); ++i){
//		printf("%c",s[i]);
		if(s[i]=='\''&&(i==0 || s[i-1]!='\\'))
			squoteflag=chstatus(squoteflag);
		else if(s[i]=='\"'&&(i==0 || s[i-1]!='\\'))
			dquoteflag=chstatus(dquoteflag);
		else if(commentflag!=1 && s[i]=='/' && s[i+1]=='*')
			commentflag=chstatus(commentflag);
		else if(commentflag==1 && s[i]=='*' && s[i+1]=='/')
			commentflag=chstatus(commentflag);
		else{ 
			if(squoteflag!=1 && dquoteflag!=1 && commentflag!=1){
				if(s[i]=='(' || s[i]=='{' || s[i]=='['){
					if(push(s[i])<0){
						printf("stack length over\n");
					}
//					printf("debug");
//					for(j=0;j<last;++j)
//						printf("%c",stack[j]);
//					printf(",%d\n",last);
				}else if(s[i]==')' || s[i]=='}' || s[i]==']'){
					if(stack[last-1]!=s[i]){
						printf("%s,%c,%d",s,stack[last],last);
						printf("syntax error\n");
					}else
						pop();
				}
			}
		}
	}
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

int push(int c)
{
	int retval;
	if(last < STACKLEN){
		if(c=='(')
			++c;
		else
			c=c+2;
		stack[last]=c;
		retval=++last;
	}else{
		retval = -1;
	}
	return retval;
}

void pop(void)
{
	if(last-1>=0)
		--last;
}
