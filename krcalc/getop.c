#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/*getop: pobiera następny operator lub operand (liczbę)*/
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/*nie jest liczbą*/
	i = 0;
	if (isdigit(c))		/*pobierz część całkowitą*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*pobierz część ułamkową*/
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
