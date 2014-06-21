#include <stdio.h>
#define TABSTOP	4

main(int argc, char *argv[])
{
	int i,c,num;
	int tabstop=TABSTOP;
	int col=0;

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

	num=0;
	while ((c=getchar())!=EOF){
		num++;
		if(col <= num && c == '\t')
			for(i = 0;i < tabstop; ++i,putchar(' '));
		else
			putchar(c);
	}
	return 0;
}

