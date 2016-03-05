#include <stdio.h>

/*kopiowanie wejścia na wyjście; pierwsza wersja*/
main()
{
	int c;
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
