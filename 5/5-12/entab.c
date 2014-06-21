#include <stdio.h>
#define TABSTOP	4

main(int argc, char *argv[])
{
	int i,c,tab;
	int tabstop=0;
	int col=0;
	int num;

	while(--argc > 0)
		switch(c=(*++argv)[0]){
			case '-':
				col = atoi(++argv[0]);
				break;
			case '+':
				tabstop = atoi(++argv[0]);
				break;
			default:
				break;
		}

	if(tabstop==0)
		tabstop=TABSTOP;

	printf("%d,%d\n",col,tabstop);

	tab=0;
	num=0;
	while ((c=getchar())!=EOF){
		num++;
		if(col <= num && c==' '){
			++tab;
			if(tab==tabstop){
				putchar('\t');
				tab=0;
			}
		}else{ 
			if(tab)
				do putchar(' ');
				while(--tab>0);
			putchar(c);
			if(c == '\n') num=0;
		}
	}

	return 0;
}
