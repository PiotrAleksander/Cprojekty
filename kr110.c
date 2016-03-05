#include <stdio.h>

#define MAXLINE 1000 /*dopuszczalna długość wiersza danych wejściowych*/

int max; /*największa znana długość*/
char line[MAXLINE]; /*bieżący wiersz wejścia*/
char longest[MAXLINE]; /*najdłuższy wiersz*/

int getline2(void);
void copy(void);

/*wypisywanie najdłuższego wiersza danych wejściowych; wersja wyspecjalizowana*/
main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline2()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0) /*był co najmniej jeden wiersz*/
		printf("%s", longest);
	return 0;
}

/*getline2: wersja wyspecjalizowana*/
int getline2(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*copy: wersja wyspecjalizowana*/
void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
