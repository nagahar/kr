#include <stdio.h>

#define RANK	128

main()
{
    int c, i, j;
    char k;
    int nWord[RANK],a[RANK];
    for (i = 0; i < RANK; ++i){
	nWord[i] = 0;
    	a[i] = 0;
    }
    while((c = getchar()) != EOF){
	 ++nWord[c];
	 a[c] = c;
    }
    printf("\n");
    for(k = 0; k < RANK; ++k){
	if(a[k] != 0){
	    printf("%c 0x%x |",a[k],a[k]);
	    for(j = 0; j < nWord[k]; ++j)
		printf("*");
	    printf("\n");
	}
    } 
}

