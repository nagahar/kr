int atoi(char *s)
{
	int sign,val;
	for(;isspace(*s);s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if(*s == '+' || *s == '-')
		s++;
	for(val=0 ; isdigit(*s); s++)
		val = 10 * val + (*s - '0');
	return val * sign;
}
