#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666

typedef struct _iobuf{
	int cnt;
	char *ptr;
	char *base;
	struct flags {
		unsigned int read:1;
		unsigned int write:1;
		unsigned int unbuf:1;
		unsigned int eof:1;
		unsigned int err:1;
	}flag;
	int fd;
}FILE;

FILE _iob[OPEN_MAX]={
	{0,(char *)0, (char *)0, {1,0,0,0,0} ,0},
	{0,(char *)0, (char *)0, {0,1,0,0,0} ,1},
	{0,(char *)0, (char *)0, {0,1,1,0,0} ,2},
};

int _fillbuf(FILE *);

#define getc(p)	(--(p)->cnt>=0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))

FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for(fp = _iob; fp<_iob+OPEN_MAX;fp++)
		if(fp->flag.read==0 ||fp->flag.write==0)
			break;
	if(fp>=_iob+OPEN_MAX)
		return NULL;

	if(*mode == 'w')
		fd=creat(name, PERMS);
	else if(*mode == 'a'){
		if((fd=open(name,O_WRONLY,0))==-1)
			fd=creat(name,PERMS);
		lseek(fd,0L,2);
	}else
		fd=open(name,O_RDONLY,0);
	if(fd==-1)
		return NULL;
	fp->fd=fd;
	fp->cnt=0;
	fp->base=NULL;
	if(*mode=='r')
		fp->flag.read=1;
	else
		fp->flag.write=1;
	return fp;
}

int _fillbuf(FILE* fp)
{
	int bufsize;

	if(fp->flag.read==0 || fp->flag.eof==1 || fp->flag.err==1)
		return EOF;
	bufsize=fp->flag.unbuf?1:BUFSIZ;
	if(fp->base==NULL)
		if((fp->base=(char *)malloc(bufsize))==NULL)
			return EOF;
	fp->ptr=fp->base;
	fp->cnt=read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt<0){
		if(fp->cnt==-1)
			fp->flag.eof=1;
		else
			fp->flag.err=1;
		fp->cnt=0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;

}

int main()
{
	FILE *fp,*fopen(char *, char *);
	char msg[10]="Error\n";
	int n;

	if((fp=fopen("input","r"))==NULL){
		write(2,msg,sizeof msg);
		exit(1);
	}

	while((n=getc(fp))!=EOF)
		write(1,&n,sizeof n);

	return 0;
}
