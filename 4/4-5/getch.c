#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
	int i=buf[bufp-1];
//	printf("buf[bufp-1]:%d,bufp:%d\n",i,bufp);
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
//	printf("c:%d,bufp%d\n",c,bufp);
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}
