#include <stdio.h>

#define BUFSIZE 100	/*maksymalny rozmiar bufora*/

int buf[BUFSIZE];	/*bufor na zwroty z ungetch*/
int bufp = 0;		/*następne wolne miejsce w buforze*/

/*getch: weź znak, być może oddany na wejście*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*ungetch: oddaj znak z powrotem na wejście*/
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: za wiele zwrotów\n");
	else
		buf[bufp++] = c;
}
