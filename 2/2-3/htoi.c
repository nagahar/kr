#include <stdio.h>

int htoi(char s[]);

main()
{
	printf("%d\n",htoi("0x1"));
	printf("%d\n",htoi("0xf"));
	printf("%d\n",htoi("0xg"));
	printf("%d\n",htoi("11"));
	printf("%d\n",htoi("ff"));

	return 0;
}

int htoi(char s[])
{
	int i,n;
	int start=0;
	int diff=0;
	if(s[0]=='0' && (s[1]=='x' || s[1]=='X'))
		start=2;
	n=0;
	for(i=start;s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F' || s[i] >= 'a' && s[i] <= 'f';++i){
		if(s[i] >= '0' && s[i] <= '9' )
			diff=s[i]-'0';	
		else if(s[i] >= 'A' && s[i] <= 'F') 
			diff=s[i]-'A'+10;	
		else if(s[i] >= 'a' && s[i] <= 'f')
			diff=s[i]-'a'+10;	
		n=16*n+diff;
	}	
	return n;
}

