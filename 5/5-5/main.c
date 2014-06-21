#include <stdio.h>

main()
{
	void strncpy(char *, char *, int n);
	void strncat(char *, char *, int n);
	int strncmp(char *, char *, int n);

	char s[]="TEST";
	char *t="DESU";
	char u[]="TEST";
	char *v="DESU";
	char w[]="DEST";
	char *x="DESU";

	strncpy(s,t,3);
	printf("%s\n",s);
	strncat(u,v,3);
	printf("%s\n",u);
	printf("%d\n",strncmp(w,x,2));
}
