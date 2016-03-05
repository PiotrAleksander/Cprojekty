#include <stdio.h>

#define TABINC 8	/*odstęp między punktami tabulacyjnymi*/

/*entab: zastąp ciągi odstępów znakami tabulacji i odstępami*/
main()
{
	int c, nb, nt, pos;

	nb = 0;		/*liczba niezbędnych odstępów*/
	nt = 0;		/*liczba niezbędnych znaków tabulacji*/
	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ') {
			if (pos % TABINC != 0)
				++nb;	/*zwiększ liczbę odstępów*/
			else {
				nb = 0;	/*skasuj odstępy*/
				++nt; 	/*za to dodaj jeden znak tabulacji*/
			}
		} else {
			for ( ; nt > 0; --nt)
				putchar('\t'); /*wypisz znak(i) tabulacji*/
			if (c == '\t')
				nb = 0;	/*zapomnij odstęp(y)*/
			else		/*wypisz odstęp(y)*/
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
		}
}
