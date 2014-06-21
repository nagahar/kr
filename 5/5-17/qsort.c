extern int start;
extern int end;
extern int separator;
void getkey(char *,int,int,int,char *);

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);
	char a[MAXLEN],b[MAXLEN];

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;

	for(i = left+1; i <= right; i++){
		getkey(v[i],start,end,separator,a);
		getkey(v[left],start,end,separator,b);
		if((*comp)(a, b) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
	char *temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
