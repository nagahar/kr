#include <stdarg.h>

void minprintf(char *fmt, ...) 
{
	va_list ap;
	va_start(ap,fmt);
	vprintf(fmt,ap);
	va_end(ap);
}
