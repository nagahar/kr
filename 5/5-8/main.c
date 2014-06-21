#include <stdio.h>

main()
{
	int day_of_year(int, int, int);
	void month_day(int, int, int *, int *);
	int m=0;
	int d=0;
	printf("%d\n",day_of_year(2005,2,28));
	month_day(2005,60,&m,&d);
	printf("%d,%d\n",m,d);
	printf("%d\n",day_of_year(2005,2,100));
	printf("%d\n",day_of_year(2005,-1,100));
	month_day(2005,-100,&m,&d);
	month_day(2005,1000,&m,&d);
}

static char daytab[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if(year < 0 || month <= 0 || day <= 0){
		printf("negative value\n");
		return -1;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(day > daytab[leap][month]){
		printf("range over\n");
		return -1;
	}
	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if(year < 0 || yearday < 0){
		printf("negative value\n");
		return;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(!leap && yearday > 365 || leap && yearday > 366){
		printf("range over\n");
		return;
	}
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
