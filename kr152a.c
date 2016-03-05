#include <stdio.h>

/*zliczanie znaków strumienia wejściowego; pierwsza wersja*/
main()
{
	long nc;
	
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
