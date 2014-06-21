int strcmpf(char *s, char *t)
{
	for(;tolower(*s)==tolower(*t);s++,t++)
		if(*s=='\0')
			return 0;
		return tolower(*s)-tolower(*t);
}
