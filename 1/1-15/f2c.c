#include <stdio.h>

int convertToFahr(int cels);

/* celsius=0,20,....,300に対して、摂氏-華氏温度対応表を印字する;浮動小数点版
 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;		/* 温度表の下限 */	
    upper = 300;	/* 上限 */
    step = 20;		/* きざみ */

    celsius = lower;
    printf("Fahrenheit Celsius\n");
    while (celsius <= upper) {
	printf("%3.0f %3.0f\n",convertToFahr(celsius),celsius);
	celsius = celsius + step;
    }
    return 0;
}

int convertToFahr(int celsius){
    return celsius * (9.0/5.0) + 32.0;
}
