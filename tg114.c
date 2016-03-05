#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15 	/*maksymalna długość histogramu*/
#define MAXCHAR 128	/*ograniczenie liczby różnych znaków*/

/*wypisz poziomy histogram częstości występowania znaków*/
main()
{
	int c, i;
	int len;		/*długość każdego wykresu*/
	int maxvalue;		/*maks. licznik wśród elementów cc[]*/
	int cc[MAXCHAR];	/*liczniki znaków o kodach = indeks*/
	
	for (i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF)
		if (c < MAXCHAR)
			++cc[c];
	maxvalue = 0;
	for (i = 1; i < MAXCHAR; ++i)
		if (cc[i] > maxvalue)
			maxvalue = cc[i]; /*maks. licznik znaków*/
	for (i = 1; i < MAXCHAR; ++ i) {
		if (isprint(i))
			printf("%5d - %c - %5d : ", i, i, cc[i]);
		else
			printf("%5d -   - %5d : ", i, cc[i]);
		if (cc[i] > 0) {
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;	/*skalowanie wykresu*/
		} else
			len = 0;
		while (len > 0) {
			putchar('*');	/*drukowanie wykresu poziomo*/
			--len;
		}
		putchar('\n');
	}
}
