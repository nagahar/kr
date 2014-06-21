#include <unistd.h>
#include <sys/file.h>

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
	int flag;
	char *base;
	int fd;
}FILE;

FILE _iob[OPEN_MAX];

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

int main()
{
	FILE *fp,*fopen(char *, char *);
	char buf[BUFSIZ];
	char msg[10]="Error\n";
	int n;

	if((fp=fopen("input","r"))==NULL){
		write(2,msg,sizeof msg);
		exit(1);
	}

	while((n=read(fp->fd,buf,BUFSIZ))>0)
		write(1,buf,n);

	return 0;
}
