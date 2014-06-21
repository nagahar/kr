#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	FILE *fp1,*fp2;
	char *prog=argv[0];
	char line1[MAXLINE],line2[MAXLINE];
	char *p1,*p2;
	int i;

	if(argc==3){
		if((fp1=fopen(*++argv,"r"))==NULL){
			fprintf(stderr,"%s: can't open %s\n",prog,*argv);
			exit(1);
		}
		if((fp2=fopen(*++argv,"r"))==NULL){
			fprintf(stderr,"%s: can't open %s\n",prog,*argv);
			exit(1);
		}

		while((p1=fgets(line1,MAXLINE,fp1))!=NULL && (p2=fgets(line2,MAXLINE,fp2))!=NULL)
			if(strcmp(line1,line2)){
				printf("<\t%s\n>\t%s\n",line1,line2);
				printf("%d",i);
				return 0;
			}
		if(p1==NULL)
			if(fgets(line2,MAXLINE,fp2)==NULL)
				printf("same file\n");
			else
				printf(">\t%s\n",line2);
		else
				printf("<\t%s\n",line1);
	}else
		printf("bad argument\n");

	return 0;
}
