#include <stdio.h>

#define MAX_CHAR	1000

main()
{
	int lim=MAX_CHAR;
	int i=0;
	char s[MAX_CHAR];
	signed char c;

	while(i<lim-1){
		if((c=getchar()) != '\n')
			if(c != EOF)
				s[i]=c;
		i++;
	}
	printf("%s\n",s);
	return 0;
}

