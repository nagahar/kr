#include <stdio.h>
#define TABSTOP	4

main()
{
	int i,c;
	while ((c=getchar())!=EOF){
		if(c == '\t')
			for(i = 0;i < TABSTOP; ++i)
				putchar(' ');	
		else
			putchar(c);
	}
}

