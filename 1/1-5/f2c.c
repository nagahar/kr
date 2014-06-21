#include <stdio.h>

/* celsius=0,20,....,300に対して、摂氏-華氏温度対応表を印字する;浮動小数点版
 */
main()
{
    int fahr;
    
    printf("Fahrenheit Celsius\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
	printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
}
