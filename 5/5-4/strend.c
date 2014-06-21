int strend(char *s, char *t)
{
	for(;*s != *t ; s++)
		if(*s == '\0')
			break;
	for(;*s == *t ; s++,t++)
		if(*t == '\0')
			break;
	if(*s || *t)
		return 0;
	else
		return 1;
}
