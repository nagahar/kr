#include <stdio.h>

main()
{
    int c, bs;
    bs='\\';
    while((c = getchar()) != EOF){
	if(c == '\t'){
	    putchar(bs);
	    c = 't';
	}
	if(c == '\b'){
	    putchar(bs);
	    c = 'b';
	}
	if(c == '\\')
	    putchar(bs);
	putchar(c);
    }
}
