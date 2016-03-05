#include <stdio.h>

/*kopiowanie wejścia na wyjście; druga wersja*/
main()
{
	int c;
	
	c = (getchar() != EOF);
	printf("%d", c);	
}
