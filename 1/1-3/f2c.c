#include <stdio.h>

/* fahr=0,20,....,300に対して、摂氏-華氏温度対応表を印字する;浮動小数点版
 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;		/* 温度表の下限 */	
    upper = 300;	/* 上限 */
    step = 20;		/* きざみ */

    fahr = lower;
    printf("Fahrenheit Celsius\n");
    while (fahr <= upper) {
	celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f %6.1f\n",fahr,celsius);
	fahr = fahr + step;
    }
}
