#include <stdio.h>

#define MAXHIST 15 /*maksymalna długość histogramu*/
#define MAXWORD 11 /*ograniczenie długości słowa*/
#define IN	 1 /*w słowie*/
#define OUT	 0 /*poza słowem*/

/*wypisz histogram długości słów pionowo*/
main()
{
	int c, i, j, nc, state;
	int maxvalue;	/*maks. licznik wśród elementów wl[]*/
	int ovflow;	/*liczba za długich słów*/
	int wl[MAXWORD];/*licznik słów o długości = indeks*/

	state = OUT;	/*poza słowem*/
	nc    = 0;	/*liczba znaków w słowie*/
	ovflow= 0;	/*liczba słów = MAXWORD lub dłuższych*/

	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;	/*koniec słowa*/
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc]; /*słowa o długości nc*/
				else
					++ovflow; /*słowo za długie*/
			nc = 0;
		} else if (state == OUT) {
			state = IN;	/*początek słowa*/
			nc = 1;
		} else 		/*wewnątrz słowa*/
			++nc;
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i]; /*maks. licznik słów*/
	
	for (i = MAXHIST; i > 0; --i) { /*dla każdego wiersza*/
		for (j = 1; j < MAXWORD; ++j)
			if (wl[j] * MAXHIST / maxvalue >= i)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');	
	if (ovflow > 0)
		printf("Było %d słów równych lub dłuższych niż %d\n", ovflow, MAXWORD - 1);
}
