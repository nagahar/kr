#include <stdio.h>
#include <limits.h>
#include <float.h>

void calc(int bit, char s[]);
void calc_smax(int bit);
void calc_umax(int bit);
void calc_min(int bit);

main()
{
	unsigned short us=1;
	unsigned int ui=1;
	unsigned long ul=1;
	float f=1;
	double d;
	long double ld=1;
	int n;

	printf("char max:%d,min:%d\n",SCHAR_MAX,SCHAR_MIN);
	printf("uchar max:%d\n",UCHAR_MAX);
	printf("shrt max:%d,min:%d\n",SHRT_MAX,SHRT_MIN);
	printf("ushrt max:%d\n",USHRT_MAX);
	printf("int max:%d,min:%d\n",INT_MAX,INT_MIN);
	printf("uint max:%u\n",UINT_MAX);
	printf("long max:%d,min:%d\n",LONG_MAX,LONG_MIN);
	printf("ulong max:%u\n",ULONG_MAX);
	
	calc(CHAR_BIT,"char");
	for(n=0;us;++n)
		us=us*2;
	calc(n,"short");
	for(n=0;ui;++n)
		ui=ui*2;
	calc(n,"int");
	for(n=0;ul;++n)
		ul=ul*2;
	calc(n,"long");
	printf("float:%e\n%e\n",FLT_MAX,FLT_MIN);
	printf("double:%e\n%e\n",DBL_MAX,DBL_MIN);
	printf("long double:%e\n%e\n",DBL_MAX,DBL_MIN);
	//printf("%lf,%lf\n",DBL_MAX,DBL_MAX);
}
void calc(int bit,char s[])
{
	printf("%s\n",s);
	printf("signed\t");
	calc_smax(bit);
	calc_min(bit);
	printf("\nunsigned\t");
	calc_umax(bit);
	printf("\n");
}

void calc_smax(int bit)
{
	int n;
	unsigned long num;
	unsigned long sum;
	num=1;
	sum=1;
	for(n=0;n<bit-2;++n){
		num=num*2;
		sum=sum+num;
	}
	printf("max:%d",sum);
}

void calc_umax(int bit)
{
	int n;
	unsigned long num;
	unsigned long sum;
	num=1;
	sum=1;
	for(n=0;n<bit-1;++n){
		num=num*2;
		sum=sum+num;
	}
	printf("max:%u",sum);
}

void calc_min(int bit)
{
	int n;
	long num;
	num=-1;
	for(n=0;n<bit-1;++n){
		num=num*2;
	}
	printf("min:%d",num);
}
