#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666

enum _flags {
	_READ	=	01,
	_WRITE	=	02,
	_UNBUF	=	04,
	_EOF	=	010,
	_ERR	=	020
};

typedef struct _iobuf{
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
}FILE;

FILE _iob[OPEN_MAX]={
	{0,(char *)0, (char *)0, _READ ,0},
	{0,(char *)0, (char *)0, _WRITE ,1},
	{0,(char *)0, (char *)0, _WRITE|_UNBUF ,2},
};

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int , FILE *);

#define getc(p)	(--(p)->cnt>=0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)	(--(p)->cnt>=0 ? (unsigned char) *(p)->ptr++=(x) : _flushbuf((x),p))

FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for(fp = _iob; fp<_iob+OPEN_MAX;fp++)
		if((fp->flag & (_READ|_WRITE))==0)
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
	fp->flag=(*mode=='r')?_READ:_WRITE;
	return fp;
}

int _fillbuf(FILE* fp)
{
	int bufsize;

	if((fp->flag&(_READ|_EOF|_ERR))!=_READ)
		return EOF;
	bufsize=(fp->flag&_UNBUF)?1:BUFSIZ;
	if(fp->base==NULL)
		if((fp->base=(char *)malloc(bufsize))==NULL)
			return EOF;
	fp->ptr=fp->base;
	fp->cnt=read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt<0){
		if(fp->cnt==-1)
			fp->flag|=_EOF;
		else
			fp->flag|=_ERR;
		fp->cnt=0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;

}

int _flushbuf(int x, FILE *fp)
{
	int bufsize;

	if(fp==NULL)
		return EOF;

	bufsize=(fp->flag&_UNBUF)?1:BUFSIZ;
	if(fp->base==NULL){
		if((fp->base=(char *)malloc(bufsize))==NULL)
			return EOF;
		fp->cnt=bufsize;
	}else
		fp->cnt=write(fp->fd,fp->base,bufsize);
	fp->ptr=fp->base;
	if(fp->cnt--!=bufsize)
		return EOF;

	return (unsigned char)*fp->ptr++=x;
}

int fflush(FILE *fp)
{
	int bufsize,n;

	if(fp==NULL){
		int i;
		for(i=0;i<OPEN_MAX;i++)
			if(_iob[i].flag&_WRITE && _iob[i].base!=NULL){
				bufsize=(_iob[i].flag&_UNBUF)?1:BUFSIZ;
				if(_iob[i].cnt==bufsize)
					return 0;
				n=write(_iob[i].fd,_iob[i].base,bufsize-_iob[i].cnt);
				if(n!=bufsize-_iob[i].cnt)
					return EOF;
				_iob[i].ptr=_iob[i].base;
				_iob[i].cnt=bufsize;
			}
	}else{
		bufsize=(fp->flag&_UNBUF)?1:BUFSIZ;
		if(fp->cnt==bufsize)
			return 0;
		n=write(fp->fd,fp->base,bufsize-fp->cnt);
		if(n!=bufsize-fp->cnt)
			return EOF;
		fp->ptr=fp->base;
		fp->cnt=bufsize;
	}
	return 0;
}

int fclose(FILE *fp)
{
	if(fp->flag&_WRITE && fflush(fp)==EOF)
		return EOF;
	free(fp->base);
	if(close(fp->fd)==-1)
		return EOF;
	return 0;
}

int main()
{
	FILE *fp,*fopen(char *, char *);
	int buf;
	char msg[10]="Error\n";

	if((fp=fopen("input","r"))==NULL){
		write(2,msg,sizeof msg);
		exit(1);
	}

	while((buf=getc(fp))!=EOF)
		putc(buf,stdout);

	fclose(fp);
	fclose(stdout);

	return 0;
}
