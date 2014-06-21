#include <stdio.h>

#define MAX_NUM 1000000

int binsearch(int x, int v[], int n);

main()
{
	int v[MAX_NUM];
	int i;
	for(i=0;i<MAX_NUM;++i)
		v[i]=i;
	printf("%d\n",binsearch(10,v,MAX_NUM));
}

int binsearch(int x, int v[], int n)
{
	int low,high,mid;

	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(x<v[mid])
			high=mid-1;
		else if(x>v[mid])
			low=mid+1;
		else
			return mid;
	}
	return -1;
}

