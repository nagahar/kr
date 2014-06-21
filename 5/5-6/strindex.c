#include <stdio.h>

int strindex(char *s, char *t)
{
	char *stmp,*ttmp;
	char *sf=s;

	for(; *s!='\0'; s++){
		for(stmp=s,ttmp=t ; *ttmp!='\0' && *stmp==*ttmp; stmp++, ttmp++)
			;
		if(ttmp > t && *ttmp == '\0') 
			return s-sf;
	}
	return -1;
}
