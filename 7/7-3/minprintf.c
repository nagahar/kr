#include <stdarg.h>

void minprintf(char *fmt, ...) 
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap,fmt);
	for(p=fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		switch(*++p){
			case 'd':
				ival=va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'f':
				dval=va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for(sval=va_arg(ap, char*); *sval; sval++)
					putchar(*sval);
				break;
			case 'o':
				ival=va_arg(ap,int);
				printf("%o",ival);
				break;
			case 'x':
				ival=va_arg(ap,int);
				printf("%x",ival);
				break;
			case 'c':
				ival=va_arg(ap,int);
				printf("%c",ival);
				break;
			case 'e':
				dval=va_arg(ap,double);
				printf("%e",dval);
				break;
			case 'g':
				dval=va_arg(ap,double);
				printf("%g",dval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
