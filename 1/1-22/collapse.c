#include <stdio.h>
#define MAXCHAR	10
#define NULLCHAR	1
#define TABSTOP	4

int getLine(char line[],int len);
int findLast(char line[]);
int size(char line[]);
int detab(char line[]);
void copy(char to[], char form[]);

main()
{
	int i,c,len,last,max;
	char line[MAXCHAR+NULLCHAR];
	max=0;
	while ((len=getLine(line, MAXCHAR+NULLCHAR)) > 0){
		max=max+len;
		if(max==len){
			len=detab(line);
			if(line[len-1]=='\n'){
				printf("%s",line);
				max=0;
			}else{
				last=findLast(line);
				for(i = 0;i <= last; ++i)
					putchar(line[i]);
				printf("...\n");
			}	
		}else
			if(line[len-1]=='\n')
				max=0;
	}
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

int findLast(char line[])
{
	int i;
	for(i = size(line)-1; i >= 0 && (line[i]=='\t' || line[i]==' ' || line[i]=='\0'); --i);
	return i;
}

int size(char s[]){
	int i;

	for(i = 0; s[i] != '\0' ; ++i);
	return ++i;
}

int detab(char s[]){
	int i,j,len,lim;
	char tmp[lim=size(s)];
	len = 0;
	i = 0;
	while(len < lim-1){
		if(s[i]=='\t'){
			for(j = len;j < lim-1 && j < len+TABSTOP ; ++j)
				tmp[j]=' ';
			len=j;
		}else{
			tmp[len]=s[i];
			++len;
		}
		++i;
	}
	tmp[len]='\0';
//	printf("%s\n",tmp);
	copy(s, tmp);
	return len;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
