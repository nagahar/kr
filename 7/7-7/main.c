#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define MAXCHAR 100

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	long lineno;
	int c, except=0,number=0,found=0;
	FILE *fp=stdin;
	char filename[MAXCHAR];
	char pattern[MAXCHAR];

	while(--argc>0 && (*++argv)[0]=='-')
		while(c=*++argv[0])
			switch(c){
				case 'x':
					except=1;
					break;
				case 'n':
					number=1;
					break;
				default:
					fprintf(stderr,"find: illegal option %c\n",c);
					argc=0;
					found=-1;
					break;
			}
	if(argc==0)
		printf("Usage: find -x -n pattern [file...]\n");
	else{
		sprintf(pattern,"%s",*argv);
		argc--;
		do{
			lineno=0;
			if(argc>0){
				sprintf(filename,"%s",*++argv);
				if((fp=fopen(filename,"r"))==NULL){
					fprintf(stderr,"can't open %s\n",filename);
					exit(1);
				}
			}
			while(fgets(line,MAXLINE,fp)!=NULL){
				lineno++;
				if((strstr(line,pattern)!=NULL)!=except){
					if(argc>0) printf("%s ",filename);
					if(number)
						printf("%ld:",lineno);
					printf("%s",line);
					found++;
				}
			}
			if(argc>0)
				fclose(fp);
		}while(--argc>0);
	}
	return found;
}
