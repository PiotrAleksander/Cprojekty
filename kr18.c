#include <stdio.h>

int power(int m, int n);

/*test funkcji power*/
main()
{
	int i;
	
	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return 0;
}

/*power: podnosi podstawę do potęgi n; n >= 0; druga wersja*/
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}
