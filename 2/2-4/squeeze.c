#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	char s1[10]="testtest";
	char s2[10]="se";
	printf("%s\n",s1);
	squeeze(s1,s2);
	printf("%s\n",s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i,j,k;
	int flag=0;
	for(i=k=0;s1[i] != '\0';i++){
		for(j=0;s2[j] != '\0';j++)
			if(s1[i] == s2[j])
				flag++;
		if(flag==0)	
			s1[k++]=s1[i];
		flag=0;
	}
	s1[k]='\0';
}

