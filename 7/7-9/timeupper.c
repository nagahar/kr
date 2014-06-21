int isupper(int c)
{
	if(('Z'-c)<0)
		return 0;
	else if(('A'-c)>=0)
		return c;
	else
		return 0;
}
