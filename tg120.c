#include <stdio.h>

#define TABINC 8 /*odstęp między punktami tabulacyjnymi*/

/*detab: zastąp znaki tabulacji odpowiednią liczbą odstępów*/
main()
{
	int c, nb, pos;

	nb = 0;		/*liczba niezbędnych odstępów*/
	pos = 1;	/*pozycja znaku w wierszu*/
	while ((c = getchar()) != EOF) {
		if (c == '\t') {	/*to znak tabulacji*/
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0) {
				putchar(' ');	/*zastąp go odstępami*/
				++pos;
				--nb;
			}
		} else if (c == '\n') {	/*to znak nowego wiersza*/
			putchar(c);
			pos = 1;
		} else {	/*wszystkie inne znaki*/
			putchar(c);
			++pos;
		}
	}
}
