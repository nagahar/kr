int strncmp(char *s, char *t, int n)
{
	for( ; *s == *t && --n; s++, t++)
		if(*s == '\0')
			return 0;
	return *s - *t;
}
