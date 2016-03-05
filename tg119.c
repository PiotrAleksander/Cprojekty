#include <stdio.h>

#define MAXLINE 1000	/*maksymalny rozmiar wiersza*/

int getline2(char line[], int maxline);
void reverse2(char s[]);

/*odwróć kolejno wszystkie wiersze wejściowe*/
main()
{
	char line[MAXLINE];	/*bieżący wiersz z wejścia*/

	while (getline2(line, MAXLINE) > 0) {
		reverse2(line);
		printf("%s", line);
	}
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

/*reverse: odwróć kolejność znaków tekstu s*/
void reverse2(char s[])
{
	int i, j;
	char temp;	/*tymczasowe miejsce na znak*/
	
	i = 0;
	while (s[i] != '\0')	/*znajdź znacznik końca tekstu*/
		++i;
	--i;			/*cofnij się przed ten znacznik*/
	if (s[i] == '\n')	/*znak nowego wiersza*/
		--i;		/*też pozostaw na miejscu*/

	j = 0;		/*początek nowego tekstu w s[]*/
	while (j < 1) {
		temp = s[j];
		s[j] = s[i];	/*zamień znaki miejscami*/
		s[i] = temp;
		--i;
		++j;
	}
}
