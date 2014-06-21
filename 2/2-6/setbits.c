#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
	unsigned x=0xff;
	unsigned y=0xf0;
	printf("0x%x,0x%x\n",x,y);
	printf("0x%x,0x%x\n",x,setbits(x,4,3,y));
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x>>(p+1-n))&~(~0<<n)|((y>>n)<<n);
}

