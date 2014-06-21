#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char source[], char pattern[]);

char pattern[] = "ould";

main()
{
	char line[MAXLINE];
	int found;

	while(getline(line, MAXLINE) > 0)
		if((found=strrindex(line, pattern)) >= 0){
			printf("%d\n",found);
		}
	return 0;
	
}
