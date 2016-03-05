#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0'	/*sygnał znaleienia liczby*/
#define NAME 'n'	/*sygnał znalezienia nazwy*/

int getch(void);
void ungetch(int);

/*getop: pobierz następny operator, liczbę lub funkcję matematyczną*/
int getop(char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (islower(c)) {	/*operator lub nazwa*/
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);	/*o jeden znak za daleko*/
		if (strlen(s) > 1)	/*więcej niż 1 znak: to nazwa*/
			return NAME;
		else
			return c;	/*to może być operator*/
	}
	if (!isdigit(c) && c != '.')
		return c;		/*to nie jest liczba*/
	if (isdigit(c))			/*buduj część całkowitą*/
		while (isdigit(s[++i] = c =getch()))
			;
	if (c == '.')			/*buduj część ułamkową*/
		while (isdigit(s[++i] = c =getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);		/*o jeden znak za daleko*/
	return NUMBER;			/*to liczba*/
}
