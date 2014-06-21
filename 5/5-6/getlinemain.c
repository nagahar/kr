#include <stdio.h>
#define MAXLINE 10

int getline(char *, int);

main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0)
		printf("%s",line);
    
    return 0;
}

