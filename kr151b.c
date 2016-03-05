#include <stdio.h>

/*kopiowanie wejścia na wyjście; druga wersja*/
main()
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(c);
}
