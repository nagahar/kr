#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define MAXCHAR 100
#define MAXNUM 10

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	int pageno=0,filepage=0;
	int lineno;
	FILE *in;
	char filename[MAXCHAR];

	if(argc==1)
		printf("Usage: cat file...\n");
	else{
		while(--argc>0){
			sprintf(filename,"%s",*++argv);
			if((in=fopen(filename,"r"))==NULL){
				fprintf(stderr,"can't open input %s\n",filename);
				exit(1);
			}
			lineno=0;
			filepage=0;
			while(fgets(line,MAXLINE,in)!=NULL){
				if(lineno++%MAXNUM==0){
					printf("------------%s:%d------------\n",filename,++filepage);
					lineno=2;
				}
				printf("%s",line);
				if(lineno==MAXNUM)
					printf("------------%d------------\n",++pageno);
			}
			if(lineno<MAXNUM){
				while(lineno++<MAXNUM)
					printf("\n");
				printf("------------%d------------\n",++pageno);
			}
			fclose(in);
		}
	}
	return 0;
}
