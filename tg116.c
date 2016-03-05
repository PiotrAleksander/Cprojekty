#include <stdio.h>

#define MAXLINE 1000	/*maksymalny rozmiar wiersza*/

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/*wypisz najdłuższy wiersz*/
main()
{
	int len;		/*długość bieżącego wiersza*/
	int max;		/*poprzednia maks. długość*/
	char line[MAXLINE];	/*bieżący wiersz z wejścia*/
	char longest[MAXLINE];	/*przechowywany maks. wiersz*/

	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0) {
		printf("%d, %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/*znaleziono wiersz*/
		printf("%s", longest);
	return 0;
}

/*getline: wczytaj wiersz do s, podaj jego długość*/
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

/*copy: przepisz tekst z 'from' do 'to'; 'to' musi być dostatecznie duże*/
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
