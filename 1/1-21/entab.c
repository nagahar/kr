#include <stdio.h>
#define TABSTOP	4

main()
{
	int i,c,tab;
	tab=0;
	while ((c=getchar())!=EOF){
		if(c == ' ')
			++tab;
		else{
			for(i = 0; i < tab ; ++i)	
				putchar(' ');
			putchar(c);
			tab=0;
		}
		if(tab==TABSTOP){
			putchar('\t');
			tab=0;
		}
	}
}
