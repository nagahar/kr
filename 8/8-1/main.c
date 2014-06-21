#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/file.h>

int main(int argc, char *argv[])
{
	int fd;
	void filecopy(int,int);
	char *prog=argv[0];

	if(argc == 1)
		filecopy(0,1);
	else
		while(--argc>0)
			if((fd=open(*++argv,O_RDONLY,0))==-1){
				fprintf(stderr,"%s: can't open %s\n",prog,*argv);
				exit(1);
			}else{
				filecopy(fd,1);
				close(fd);
			}
	exit(0);
}

void filecopy(int inf, int outf)
{
	void error(char*,...);
	char buf[BUFSIZ];
	int n;
	while((n=read(inf,buf,BUFSIZ))>0)
		if(write(outf,buf,n)!=n)
			error("cat: write error on file");
}

void error(char *fmt,...)
{
	va_list args;

	va_start(args,fmt);
	fprintf(stderr,"error: ");
	vfprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end(args);
	exit(1);
}
