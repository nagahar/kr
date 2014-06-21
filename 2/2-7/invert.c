#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	unsigned x=0xf7;
	printf("0x%x\n",x);
	printf("0x%x\n",invert(x,4,2));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned t;
	t=(~(x>>(p+1-n))&~(~0<<n))<<(p+1-n);
	return ((x>>(p+1))<<p+1)|t|(x&~(~0<<(p+1-n)));
}

