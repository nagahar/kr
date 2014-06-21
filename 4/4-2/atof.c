#include <ctype.h>

double atof(char s[])
{
	double val, power;
	int i, j, sign, expsign, exp; 

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i]=='-') ? -1: 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val=0.0;isdigit(s[i]);i++)
		val=10.0 * val + (s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++){
		val=10.0 * val + (s[i]-'0');
		power*=10.0;
	}
	if(s[i]=='e' || s[i]=='E'){
		i++;
		expsign = s[i] == '-' ? -1:1;
		i++;
		for(exp=0;isdigit(s[i]);i++)
			exp=10 * exp + (s[i]-'0');
		for(j=0;j<exp;j++){
			if(expsign==1)
				val*=2.0;
			else
				val/=2.0;
		}
	}

	return sign * val / power ;
}
