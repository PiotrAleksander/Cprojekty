#include <stdio.h>

#define MAXCOL 10	/*maksymalna pozycja w tekście wejściowym*/
#define TABINC 8	/*odstęp między punktami tabulacyjnymi*/

char line[MAXCOL];	/*wiersz budowany ze znaków z wejścia*/

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/*przełam długie wiersze wejściowe na dwa lub więcej krótszych wierszy*/
main()
{
	int c, pos;

	pos = 0;	/*bieżąca pozycja w wierszu*/
	while ((c = getchar()) != EOF) {
		line[pos] = c;	/*zapisz bieżący znak w wierszu*/
		if (c == '\t')	/*gdy znak tabulacji*/
			pos = exptab(pos);	/*zastąp go odstępami*/
		else if (c == '\n') {	/*dla znaku nowego wiersza*/
			printl(pos);	/*wypisz bieżący wiersz*/
			pos = 0;
		} else if (++pos >= MAXCOL) {	/*za długi tekst*/
			pos = findblnk(pos);	/*znajdź odstęp*/
			printl(pos);		/*wypisz do odstępu*/
			pos = newpos(pos);	/*przebuduj wiersz*/
		}
	}
	return 0;
}

/*printl: wypisz wiersz do pozycji pos*/
void printl(int pos)
{
	int i;
	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	if (pos > 0)		/*gdy cokolwiek wypisano*/
		putchar('\n');	/*zakończ wiersz*/
}

/*exptab: jeden znak tabulacji zastąp znakami odstępu;
	  znak tabulacji jest przynajmniej jednym odstępem*/
int exptab(int pos)
{
	line[pos] = ' ';
	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';
	if (pos < MAXCOL)	/*zostało wolne miejsce w wierszu*/
		return pos;
	else {		/*wypełniono bieżący wiersz*/
		printl(pos);
		return 0;	/*bieżąca pozycja od początku wiersza*/
	}
}

/*findblnk: szukaj wstecz znaku odstępu od pozycji pos*/
int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)	/*nie ma w wierszu znaków odstępu?*/
		return MAXCOL;
	else 		/*jest przynajmniej jeden znak odstępu*/
		return pos+1; /*pozycja po tym znaku*/
}

/*newpos: przebuduj wiersz i podaj nową pozycję*/
int newpos(int pos)
{
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)
		return 0;	/*nic nie trzeba przebudować*/
	else {
		i = 0;		/*przesuń znaki na początek*/
		for (j = pos; j < MAXCOL; ++j) {
			line[i] = line[j];
			++i;
		}
		return i;
	}
}
