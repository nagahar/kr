#include <stdio.h>

#define MAX_NUM 1000000

int binsearch(int x, int v[], int n);

main()
{
	int v[MAX_NUM];
	int i,j;
	for(i=0;i<MAX_NUM;++i){
		v[i]=i;
	//	j+=2;
	}
	printf("%d\n",binsearch(10,v,MAX_NUM));
	//printf("%d\n",binsearch(10000,v,MAX_NUM));
	//printf("%d\n",binsearch(99,v,MAX_NUM));
	//printf("%d\n",binsearch(-1,v,MAX_NUM));
	//printf("%d\n",binsearch(3,v,MAX_NUM));
}

int binsearch(int x, int v[], int n)
{
	int low,high,mid;

	low=0;
	high=n-1;
	if(x>v[high] || x<v[low])
		return -1;
	while(low<=high){
		mid=(low+high)/2;
		if(x<v[mid])
			high=mid-1;
		else 
			low=mid+1;
	}
	return x==v[high]?high:-1;
}
