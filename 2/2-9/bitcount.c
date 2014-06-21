#include <stdio.h>

unsigned bitcount(unsigned x);

/*
 * 	2の補数では(-1)=>111...1となるため、
 * 	(x-1)によってxの最も右の1のビットは必ず反転する
 * 	そのためx&(x-1)でxの最も右の1のビットは必ず0になる
 */
main()
{
	int x=0xff;
	printf("0x%x\n",x);
	printf("%d\n",bitcount(x));
	return 0;
}

unsigned bitcount(unsigned x)
{
	int b;
	for(b=0;x!=0;b++)
		x&=x-1;
	return b;
}

