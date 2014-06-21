#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	char s1[10]="testtest";
	char s2[10]="se";
	printf("%s\n",s1);
	printf("%d\n",any(s1,s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int i,j;
	int index=-1;
	for(i=0;s1[i] != '\0';i++)
		for(j=0;s2[j] != '\0';j++)
			if(s1[i] == s2[j] && index<0)
				index=i;
	
	return index;
}

