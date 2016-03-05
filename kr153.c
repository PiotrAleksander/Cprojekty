#include <stdio.h>

/*zliczanie wierszy strumienia wejściowego*/
main()
{
	int c, nl;
	
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
