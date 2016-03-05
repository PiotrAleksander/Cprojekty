#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

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
