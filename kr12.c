#include <stdio.h>

/*drukowanie tabeli przeliczeniowej stopni Fahrenheita na stopnie Celsjusza*/
/*dla wartości fahr = 0, 20, ..., 300*/
main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;   /*dolne ograniczenie skali temperatury*/
	upper = 300; /*górne ograniczenie*/
	step = 20;   /*postąpienie*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
