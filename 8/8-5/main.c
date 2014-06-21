#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void fsize(char *);

int main(int argc, char **argv)
{
	if(argc == 1)
		fsize(".");
	else
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}

void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name)
{
	struct stat stbuf;

	if(stat(name, &stbuf)==-1){
		fprintf(stderr,"fsize: can't access %s\n", name);
		return;
	}
	if((stbuf.st_mode & S_IFMT)==S_IFDIR)
		dirwalk(name, fsize);
	printf("name:%8s\n",name);
	printf("dev:%8lld\n",stbuf.st_dev);
	printf("ino:%8ld\n",stbuf.st_ino);
	printf("mode:%8ho\n",stbuf.st_mode);
	printf("nlink:%8hd\n",stbuf.st_nlink);
	printf("uid:%8hd\n",stbuf.st_uid);
	printf("gid:%8hd\n",stbuf.st_gid);
	printf("rdev:%8lld\n",stbuf.st_rdev);
	printf("size:%8ld\n",stbuf.st_size);
	printf("blksize:%8ld\n",stbuf.st_blksize);
	printf("blocks:%8ld\n",stbuf.st_blocks);
	printf("atime:%8ld\n",stbuf.st_atime);
	printf("mtime:%8ld\n",stbuf.st_mtime);
	printf("ctime:%8ld\n",stbuf.st_ctime);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if((dfd=opendir(dir))==NULL){
		fprintf(stderr,"dirwalk: can't open %s\n",dir);
		return;
	}
	while((dp=readdir(dfd))!=NULL){
		if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
			continue;
		
		if(strlen(dir)+strlen(dp->d_name)+2>sizeof(name))
			fprintf(stderr,"dirwalk: name %s/%s too long\n",dir,dp->d_name);
		else{
			sprintf(name, "%s/%s",dir,dp->d_name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

