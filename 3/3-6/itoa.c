#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256
void itoa(int n, char s[],int f);
void reverse(char s[]);

main()
{
	int n=-1000;
	char s[MAX_CHAR];

	printf("%d\n",n);
	itoa(n,s,10);
	printf("%s\n",s);
}

void itoa(int n, char s[], int f)
{
	int i, sign;
	unsigned int ui;

	if((sign=n)<0)
		ui=-n;
	i=0;
	do {
		s[i++]= ui%10 +'0';
	}while((ui/=10)>0);

	if(sign<0)
		s[i++]='-';
	for(;i<f;i++)
		s[i]=' ';
		
	s[i]='\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;
	for(i=0, j=strlen(s)-1;i<j;i++,j--){
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}
