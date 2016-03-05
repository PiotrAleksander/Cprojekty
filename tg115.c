#include <stdio.h>

float celsius(float fahr);

/*wypisz zestawienie temperatur Fahrenheita-Celsjusza
  dla fahr = 0, 20, ..., 300; wersja zmiennoprzecinkowa*/
main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;	/*dolna granica temperatur*/
	upper = 300;	/*górna granica temperatur*/
	step = 20;	/*rozmiar kroku*/

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f  %6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

/*celsius: zamień stopnie Fahrenheita na Celsjusza*/
float celsius(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
