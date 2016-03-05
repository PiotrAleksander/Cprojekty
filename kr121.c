#include <stdio.h>

/*drukowanie tabeli przeliczeniowej stopni Fahrenheita na stopnie Celsjusza*/
/*dla wartości fahr = 0, 20, ..., 300*/
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;   /*dolne ograniczenie skali temperatury*/
	upper = 300; /*górne ograniczenie*/
	step = 20;   /*postąpienie*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
