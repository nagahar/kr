#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define SIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char strline[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main()
{
	int nlines;
	char strline[SIZE];

	if((nlines=readlines(lineptr,strline, MAXLINES)) >= 0){
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], char strline[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *pline=strline;

	nlines=0;
	while((len=getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || strline+SIZE-pline < len)
			return -1;
		else {
			line[len-1]='\0';
			strcpy(pline, line);
			lineptr[nlines++] = pline;
			pline += len;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	while(nlines-->0)
		printf("%s\n",*lineptr++);
}
