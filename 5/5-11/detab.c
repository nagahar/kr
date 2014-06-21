#include <stdio.h>
#define TABSTOP	4

main(int argc, char *argv[])
{
	int i,c;
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

	while ((c=getchar())!=EOF){
		if(c == '\t')
			for(i = 0;i < tabstop; ++i)
				putchar(' ');	
		else
			putchar(c);
	}
	return 0;
}

