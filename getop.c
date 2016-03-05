#include <ctype.h>

int getch(void);
void ungetch(int);

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

#define BUFSIZE 100

char buf[BUFSIZE];	/*bufor dla ungetch*/
int bufp = 0;		/*następna wolna pozycja w buforze*/

int getch(void)		/*pobiera znak (może być znakiem wcześniej wycofanym)*/
{
	return (bufp > 0) ? buf[--bufp] : getch();
}

void ungetch(int c)	/*wycofuje znak do strumienia danych wejściowych*/
{
	if (bufp >= BUFSIZE)
		printf("ungetch: zbyt wiele znaków\n");
	else
		buf[bufp++] = c;
}
