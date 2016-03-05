#include <stdio.h>

#define IN 1 /*wewnątrz słowa*/
#define OUT 0 /*poza słowem*/

/*zliczanie wierszy, słów i znaków*/
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("Wiersze:%d; Słowa: %d; Znaki: %d\n", nl, nw, nc);
}
