void strncat(char *s, char *t, int n)
{
	while (*s++)
		;
	s--;
	while ((*s++ = *t++) && --n)
		;
	if(!n)
		*s = '\0';
}
