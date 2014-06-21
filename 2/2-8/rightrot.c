#include <stdio.h>

unsigned rightrot(unsigned x, int n);

main()
{
	unsigned x=0xff;
	printf("0x%x\n",x);
	printf("0x%x\n",rightrot(x,2));
	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	unsigned t;
	unsigned ui=1;
	int i;
	t=(x&~(~0<<n));
	printf("0x%x\n",t);
	for(i=0;ui;++i)
		ui=ui*2;
	return (x>>n)|(t<<i-n);
}

