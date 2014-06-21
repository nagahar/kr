int getstart(char *v,int start, int separator)
{
	char *tmp;
	int i=0;
	int retval;

	if(start==0 || separator==0)
		return 0;
	retval=(int)v;
	while((tmp=index(v,separator))!=NULL){
		if(start==++i)
			break;
		v=tmp+1;
	}
	if(tmp!=NULL){
		retval=(int)tmp+1-retval;
		return retval;
	} else{
		return 0;
	}
}

int getend(char *v, int end, int separator)
{
	char *tmp;
	int i=0;
	int retval;

	retval=(int)v;
	while((tmp=index(v,separator))!=NULL){
		if(end<++i)
			break;
		v=tmp+1;
	}
	if(tmp!=NULL){
		retval=(int)tmp+1-retval;
		return retval;
	} else{
		return MAXLEN;
	}
}

void getkey(char *orig, int start,int end,int separator, char *key)
{
	int num=getend(orig,end,separator)-getstart(orig,start,separator)-1;
	strncpy(key,(char*)(orig+getstart(orig,start,separator)),num);
	key[num]='\0';
}
