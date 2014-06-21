#include <stdio.h>
#define TABSTOP	4

main(int argc, char *argv[])
{
	int i,c,tab;
	int tabstop=TABSTOP;

	while(--argc > 0 && (*++argv)[0]=='-')
		while(c=*++argv[0])
			switch(c){
				case 't':
					break;
				default:
					argc=0;
					break;
			}
	if(argc > 0)
		tabstop=atoi(*argv);
	
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
		if(tab==tabstop){
			putchar('\t');
			tab=0;
		}
	}

	return 0;
}
