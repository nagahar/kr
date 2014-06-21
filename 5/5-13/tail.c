#include <stdio.h>
#include <stdlib.h>
#define	MAX_LINE	10000

int readtail(char *[], int, int);
void writetail(char *[], int, int);

int main(int argc, char *argv[])
{
	char c;
	int row=10;
	char *lineptr[MAX_LINE];
	int nlines;

	while(--argc > 0)
		switch(c=(*++argv)[0]){
			case '-':
				row=atoi(++argv[0]);
				break;
			default:
				break;
		}
	if(row>MAX_LINE) row=MAX_LINE;

	if((nlines=readtail(lineptr,MAX_LINE,row))>0)
		writetail(lineptr,nlines,row);
	else
		printf("input file is too big!!\n");

	return 0;
}

#define MAX_LEN	1000

int getline(char *, int);
char *alloc(int);
void afree(char *);

int readtail(char *lineptr[], int maxline, int row)
{
	char line[MAX_LEN];
	int nlines;
	char *p;
	int len;
	char *tmpptr[maxline];

	nlines=0;
	while((len=getline(line, MAX_LEN))>0){
		if((p=alloc(len))==NULL){
			return -1;
		}
		if(nlines>=maxline)
			nlines=0;
		line[len-1]='\0';
		strcpy(p,line);
		lineptr[nlines++]=p;
	}
	if(nlines<row){
		int i;
		for(i=0;i<maxline;tmpptr[i]=lineptr[i],i++);
		for(i=0;i<maxline-nlines;lineptr[i]=tmpptr[i+nlines],i++);
		for(i=0;i<nlines;lineptr[i+maxline-nlines]=tmpptr[i],i++);
		nlines=maxline;
	}
	return nlines;
}

void writetail(char *lineptr[], int nlines, int row)
{
	int i;
	for(i=nlines-row;i<nlines;i++)
		printf("%s\n",*(lineptr+i));
}
