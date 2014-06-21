#include <stdio.h>

#define	IN	1
#define OUT	0

main()
{
    int c, nl, nw, nc, state;
    
    state = OUT;
    nw=0;
    while((c = getchar()) != EOF){
	if(c == ' ' || c == '\n' || c == '\t'){
	    state = OUT;
	}else if (state == OUT){
	    state = IN;
	    if(nw > 0)
		putchar('\n');	
	    ++nw;
	    putchar(c);
	}else if (state == IN){
	    putchar(c);
	}
	if(c == '\n'){
	    nw=0;
	    putchar('\n');
	}
    }
}
