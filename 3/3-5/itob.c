#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void itob(unsigned int n, char s[], int b);
void reverse(char s[]);

main()
{
	int n=31;
	char s[MAX_CHAR];

	printf("%d\n",n);
	itob(n,s,16);
	printf("%s\n",s);
}

void itob(unsigned int n, char s[], int b)
{
	int i, sign, num;

	if(b<0) return;

	i=0;
	do {
		num=n%b +'0';
		switch(n%b){
			case 10:
				num='A';
				break;
			case 11:
				num='B';
				break;
			case 12:
				num='C';
				break;
			case 13:
				num='D';
				break;
			case 14:
				num='E';
				break;
			case 15:
				num='F';
				break;
		}
		s[i++]=num; 
	}while((n/=b)>0);

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
