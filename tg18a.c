#include <stdio.h>

/*zlicz znaki odstępu, tabulacji i nowego wiersza; wersja z else*/
main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;

	while ((c = getchar()) != 'A')
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	printf("%d %d %d\n", nb, nt, nl);
}
