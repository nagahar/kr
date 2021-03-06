#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
	int numeric=0, reverse=0;
	int c, nlines;

	while(--argc > 0 && (*++argv)[0]=='-')
		while(c = *++argv[0])
			switch(c){
				case 'n':
					numeric=1;
					break;
				case 'r':
					reverse=1;
					break;
				default:
					printf("Illegal option %c\n",c);
					argc=0;
					return -1;
			}
		
	if((nlines=readlines(lineptr, MAXLINES))>=0){
		qsort((void **)lineptr, 0, nlines-1, 
				(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr,nlines,reverse);
		return 0;
	}else{
		printf("Input too big to sort\n");
		return 1;
	}

}
