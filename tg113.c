#include <stdio.h>

#define MAXHIST 15 /*maksymalna długość histogramu*/
#define MAXWORD 11 /*ograniczenie długości słowa*/
#define IN	 1 /*w słowie*/
#define OUT	 0 /*poza słowem*/

/*wypisz histogram długości słów poziomo*/
main()
{
	int c, i, nc, state;
	int len;	/*długość każdego wykresu*/
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
		} else
			++nc;
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i]; /*maks. licznik słów*/
	
	for (i = 1; i < MAXWORD; ++i) { /*dla każdego licznika*/
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1; /*skalowanie wykresu*/
		} else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0)
		printf("Było %d słów równych lub dłuższych niż %d\n", ovflow, MAXWORD - 1);
}
