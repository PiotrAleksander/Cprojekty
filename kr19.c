#include <stdio.h>
#define MAXLINE 1000 /*dopuszczalna długość wiersza danych wejściowych*/

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/*wypisywanie najdłuższego wiersza danych wejściowych*/
main()
{
	int len; /*długość bieżącego wiersza*/
	int max; /*największa znana długość*/
	char line[MAXLINE]; /*bieżący wiersz wejścia*/
	char longest[MAXLINE]; /*najdłuższy wiersz*/

	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /*dane zawierały co najmniej jeden wiersz*/
		printf("%s", longest);
	return 0;
}

/*getline: pobiera wiersz do tablicy s, zwraca długość*/
int getline2(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*copy: kopiuje 'from' do 'to', zakłada wystarczający rozmiar*/
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}	
