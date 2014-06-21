#include <ctype.h>

int dircmp(char *s, char *t)
{
	int check_string(char);
	char *tmps,*tmpt;

	tmps=s;
	tmpt=t;
	while(check_string(*s))
		s++;
	while(check_string(*t))
		t++;
	for(;*s==*t;s++,t++){
		if(*s=='\0')
			return 0;
		if(check_string(*s)){
			while(check_string(*s))
				s++;
			s--;
		}
		if(check_string(*t)){
			while(check_string(*t))
				t++;
			t--;
		}
	}
	return *s-*t;
}

int dircmpf(char *s, char *t)
{
	int check_string(char);
	int strcmpf(char *, char *);
	char *tmps,*tmpt;

	tmps=s;
	tmpt=t;
	while(check_string(*s))
		s++;
	while(check_string(*t))
		t++;
	for(;tolower(*s)==tolower(*t);s++,t++){
		if(*s=='\0')
			return 0;
		if(check_string(*s)){
			while(check_string(*s))
				s++;
			s--;
		}
		if(check_string(*t)){
			while(check_string(*t))
				t++;
			t--;
		}
	}
	return tolower(*s)-tolower(*t);
}

int check_string(char s)
{
	if(s!='\0' && !isspace(s) && !isalnum(s))
		return 1;
	else
		return 0;

}
