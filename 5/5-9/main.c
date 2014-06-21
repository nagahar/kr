#include <stdio.h>

main()
{
	static char daytab[2][13]={
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};
	int day_of_year(int, int, int, char [][]);
	void month_day(int, int, int *, int *, char [][]);
	int m=0;
	int d=0;
	printf("%d\n",day_of_year(2005,2,28,daytab));
	printf("%d\n",day_of_year(2005,2,100,daytab));
	printf("%d\n",day_of_year(2005,-1,100,daytab));
	month_day(2005,60,&m,&d,daytab);
	printf("%d,%d\n",m,d,daytab);
	month_day(2005,-100,&m,&d,daytab);
	month_day(2005,1000,&m,&d,daytab);
}


int day_of_year(int year, int month, int day, char daytab[][13])
{
	int i, leap;
	char *p;

	if(year < 0 || month <= 0 || day <= 0){
		printf("negative value\n");
		return -1;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p=leap ? *++daytab:*daytab;
	if(day > *(p+month)){
		printf("range over\n");
		return -1;
	}
	for(p++; p-*daytab < month; p++){
		day += *p;
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday, char daytab[][13])
{
	int leap;
	char *p;

	if(year < 0 || yearday < 0){
		printf("negative value\n");
		return;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(!leap && yearday > 365 || leap && yearday > 366){
		printf("range over\n");
		return;
	}
	p=leap ? *++daytab:*daytab;
	for(p++; yearday > *p; p++)
		yearday -= *p;
	*pmonth =p-*daytab; 
	*pday = yearday;
}

