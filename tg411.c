#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'	/*sygnał znalezienia liczby*/

int getch(void);

/*getop: pobierz następny operator lub liczbę*/
int getop(char s[])
{
	int c, i;
	static int lastc = 0;	/*ostatnio wczytany znak*/

	if (lastc == 0)
		c = getch();
	else {
		c = lastc;
		lastc = 0;
	}
	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/*to nie jest liczba: to operator*/
	i = 0;
	if (isdigit(c))		/*buduj część całkowitą*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*buduj część ułamkową*/
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	return NUMBER;		/*to liczba*/
}
