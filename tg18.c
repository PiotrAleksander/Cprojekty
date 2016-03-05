#include <stdio.h>

/*zlicza znaki odstępu, tabulacji i nowego wiersza*/
main()
{
	int c, nb, nt, nl;

	nb = 0;
	nt = 0;
	nl = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}
	printf("znaki odstępu: %d; znaki tabulacji: %d; znaki nowego wiersza: %d\n", nb, nt, nl);
}
