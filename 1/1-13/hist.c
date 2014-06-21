#include <stdio.h>

#define RANK	15
#define WIDTH	1

main()
{
    int c, nc, i, j, max;
    int nWord[RANK];
    nc = 0;
    max = 0;
    for (i = 0; i < RANK; ++i)
	nWord[i] = 0;
    while((c = getchar()) != EOF){
	if(c == ' ' || c == '\n' || c == '\t'|| c == ',' || c == '.'){
	   if(nc != 0 && nc <= RANK * WIDTH){
		++nWord[nc/WIDTH];
	    }
	    nc=0;
	}else {
	    ++nc;
	}
    }
    printf("\n");
    for(i = 0; i < RANK; ++i){
	printf("%2d-%2d |",i*WIDTH,(i+1)*WIDTH);
	for(j = 0; j < nWord[i]; ++j)
	    printf("*");
	printf("\n");
    }
    for(i = 0; i < RANK; ++i){
	if(max < nWord[i]){
	    max = nWord[i];
	}
    }
    for(i = max; i > 0; --i){
	for(j = 0; j < RANK; ++j){
	    if(nWord[j] >= i)
		printf("  **  ");
	    else
		printf("      ");
	}
	printf("\n");
    }
    for(i = 0; i < RANK; ++i)
	printf("%2d-%2d ",i*WIDTH,(i+1)*WIDTH);
    printf("\n");
}
