#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int strcmpf(char *, char *);
int dircmp(char *, char *);
int dircmpf(char *, char *);

int main(int argc, char *argv[])
{
	int reverse=0,numeric=0,fold=0,directory=0;
	int c, nlines;

	while(--argc > 0 && (*++argv)[0]=='-')
		while((c = *++argv[0])!='\0')
			switch(c){
				case 'n':
					numeric=1;
					break;
				case 'r':
					reverse=1;
					break;
				case 'f':
					fold=1;
					break;
				case 'd':
					directory=1;
					break;
				default:
					printf("Illegal option %c\n",c);
					argc=0;
					return -1;
			}
	if((nlines=readlines(lineptr, MAXLINES))>=0){
		if(numeric)
			qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))numcmp);
		else if(fold && directory)
			qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))dircmpf);
		else if(fold)
			qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))strcmpf);
		else if(directory)
			qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))dircmp);
		else
			qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))strcmp);
		writelines(lineptr,nlines,reverse);
		return 0;
	}else{
		printf("Input too big to sort\n");
		return 1;
	}

}
