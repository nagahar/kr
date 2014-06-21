char buf;
int status;

int getch(void)
{
	if(status > 0){
		status=0;
		return buf;
	}else
		return getchar();
}

void ungetch(int c)
{
	if(status > 0)
		printf("ungetch: too many characters\n");
	else{
		buf=status=c;
	}
}

