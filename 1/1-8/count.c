#include <stdio.h>

main()
{
    int c, nl, sp, tab;
    nl=0;
    sp=0;
    tab=0;
    while((c = getchar()) != EOF){
	if(c == ' ')
	    ++sp;
	if(c == '\t')
	    ++tab;
	if(c == '\n')
	    ++nl;
    }
    printf("%d,%d,%d\n",sp,tab,nl);
}
