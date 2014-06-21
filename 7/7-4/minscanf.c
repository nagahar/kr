#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...) 
{
	va_list ap;
	char *c;
	char *p;
	char *sval;
	int *ival;
	float *dval;

	va_start(ap,fmt);
	for(p=fmt; *p; p++){
		if(*p != '%'){
			if(*c!=*p)
				return;
			continue;
		}
		switch(*++p){
			case 'd':
				ival=va_arg(ap,int*);
				scanf("%d",ival);
				break;
			case 'f':
				dval=va_arg(ap,float*);
				scanf("%f",dval);
				break;
			case 's':
				sval=va_arg(ap, char*);
				scanf("%s",sval);
				break;
			case 'o':
				ival=va_arg(ap,int*);
				scanf("%o",ival);
				break;
			case 'x':
				ival=va_arg(ap,int*);
				scanf("%x",ival);
				break;
			case 'c':
				c=va_arg(ap,char*);
				scanf("%1s",c);
				break;
			case 'e':
				dval=va_arg(ap,float*);
				scanf("%e",dval);
				break;
			case 'g':
				dval=va_arg(ap,float*);
				scanf("%g",dval);
				break;
			default:
				if(*c!=*p)
					return;
				break;
		}
	}
	va_end(ap);
}
