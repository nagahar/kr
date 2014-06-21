char *lineptr[MAXLINES];
int nlines;
int start;
int end;
int separator;
int field[MAXOPTIONS][MAXORDER];
static int s[MAXOPTIONS],e[MAXOPTIONS];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
int *getcmp(int);
void getkey(char *, int, int, int, char *);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int strcmpf(char *, char *);
int dircmp(char *, char *);
int dircmpf(char *, char *);

int getline(char *, int);
char *alloc(int);
int atoi(char*);

int main(int argc, char *argv[])
{
	int key=0,reverse=0;
	int c;
	int opt=0;

	while(--argc > 0 && (*++argv)[0]=='-'){
		while((c = *++argv[0])!='\0')
			switch(c){
				case 'r':
					reverse=1;
					break;
				case 'n': case 'f': case 'd':
					field[opt][c]=1;
					break;
				case 'k':
					key=1;
					s[opt]=atoi(++argv[0]);
					if(*argv[0]==',')
						e[opt]=atoi(++argv[0]);
					else if(s[opt]==0)
						e[opt]=MAXLEN;
					else
						e[opt]=s[opt];
					while(isdigit(++argv[0]));
					--argv[0];
					break;
				case 't':
					separator=*++argv[0];
					break;
				default:
					printf("Illegal option %c\n",c);
					argc=0;
					return -1;
			}
		if(key){
			opt++;
			key=0;
		}
	}
	if((nlines=readlines(lineptr, MAXLINES))>=0){
		int j=0;
		do{
			if(j==0)
				qsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))getcmp(j));
			else{
				int from=0;
				char a[MAXLEN],b[MAXLEN];
				int i;
				for(i=0;i<nlines-1;i++){
					getkey(lineptr[i],s[j-1],e[j-1],separator,a);
					getkey(lineptr[i+1],s[j-1],e[j-1],separator,b);

					if(((int (*)(void *, void *))getcmp(j-1))(a,b)!=0){
						qsort((void **)lineptr, from, i, (int (*)(void *, void *))getcmp(j));
						from=i+1;
					}
				}
			}
		}while(++j<opt);

		writelines(lineptr,nlines,reverse);
		return 0;
	}else{
		printf("Input too big to sort\n");
		return 1;
	}
}

int *getcmp(int opt)
{
	int *func;

	start=s[opt];
	end=e[opt];
	if(field[opt]['n']==1){
		func=(int *)numcmp;
	}else if(field[opt]['d']==1 && field[opt]['f']==1){
		func=(int *)dircmpf;
	}else if(field[opt]['f']==1){
		func=(int *)strcmpf;
	}else if(field[opt]['d']==1){
		func=(int *)dircmp;
	}else{
		func=(int *)strcmp;
	}
	return func;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines=0;
	while((len=getline(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len))==NULL)
			return -1;
		else {
			line[len-1]='\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse)
{
	while(nlines-- > 0)
		if(reverse)
			printf("%s\n",lineptr[nlines]);
		else
			printf("%s\n",*lineptr++);
}
