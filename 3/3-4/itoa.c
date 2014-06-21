#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
 * 2の補数表現では最小値(負数)の絶対値は最大値(正数)の絶対値よりも1大きいため
 * 正数として表現できない(オーバーフローする)
 */

#define MAX_CHAR 256
void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	int n=INT_MIN;
	char s[MAX_CHAR];

	printf("%d,%d\n",n,INT_MAX);
	itoa(n,s);
	printf("%s\n",s);
}

void itoa(int n, char s[])
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
