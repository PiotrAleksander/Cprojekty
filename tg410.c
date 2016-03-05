#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER '0'

int getline(char line[], int limit);

int li = 0;	/*pozycja w wierszu*/
char line[MAXLINE];	/*wiersz z wejścia*/

/*getop: pobierz następny operator lub liczbę*/
int getop(char s[])
{
	int c, i;

	if (line[li] == '\0')
		if (getline(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/*to nie jest liczba; to operator*/
	i = 0;
	if (isdigit(c))		/*buduj część całkowitą*/
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;		/*to liczba*/
}
