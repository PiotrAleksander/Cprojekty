#include <stdio.h>

#define MAXLINE 1000	/*maksymalny rozmiar wiersza*/

int getline2(char line[], int maxline);
int remove2(char s[]);

/*usuń końcowe znaki odstępu i tabulacji oraz puste wiersze*/
main()
{
	char line[MAXLINE];	/*bieżący wiersz z wejścia*/

	while (getline2(line, MAXLINE) > 0)
		if (remove2(line) > 0)
			printf("%s", line);
	return 0;
}

int getline2(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2) {
			s[j] = c;	/*wiersz ciągle w granicach*/
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}

/*remove: usuwa końcowe znaki odstępu i tabulacji z s*/
int remove2(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\n')	/*znajdź znak nowego wiersza*/
		++i;
	--i;		/*cofnij się przed ten znak*/
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;	/*pomiń od końca białe znaki*/

	if (i >= 0) {	/*jeżeli wiersz nie jest pusty*/
		++i;
		s[i] = '\n';	/*oddaj znak nowego wiersza*/
		++i;
		s[i] = '\0';	/*dodaj znacznik końca tekstu*/
	}
	return i;
}
