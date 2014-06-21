void strncpy(char *s, char *t, int n)
{
	while((*s++ = *t++) && --n)
		;
	if(!n){
		*s = '\0';
	}
}
