#include <stdio.h>

#define swap(T,X,Y) ({T tmp;tmp=X,X=Y,Y=tmp;})

main()
{
	int i=0;
	int j=1;
	swap(int,i,j);
	printf("%d,%d\n",i,j);
}
