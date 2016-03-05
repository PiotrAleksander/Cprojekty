#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/*usuń wszystkie komentarze z POPRAWNEGO programu w C*/
main()
{
	int c, d;

	while ((c = getchar()) != EOF)
		rcomment(c);
	return 0;
}

/*rcomment: czytaj każdy znak, usuń komentarze*/
void rcomment(int c)
{
	int d;

	if (c == '/')
		if ((d = getchar()) == '*')
			in_comment();	/*początek komentarza*/
		else if (d == '/') {
			putchar(c);	/*drugi znak / */
			rcomment(d);
		} else {
			putchar(c);	/*to nie jest komentarz ;)*/	
			putchar(d);
		}
	else if (c == '\'' || c == '"')
		echo_quote(c);		/*to początek stałej*/
	else
		putchar(c);		/*to nie jest komentarz*/
}

/*in_comment: szukaj końca POPRAWNEGO komentarza*/
void in_comment(void)
{
	int c, d;

	c = getchar();		/*poprzedni znak*/
	d = getchar();		/*bieżący znak*/
	while (c != '*' || d != '/') {	/*szukaj końca*/
		c = d;
		d = getchar();
	}
}

/*echo_quote: wypisz tekst stałej i znajdź jego koniec*/
void echo_quote(int c)
{
	int d;

	putchar(c);	/*wypisz znak otwierający stałą*/
	while ((d = getchar()) != c) {
		putchar(d);	/*wypisz jej tekst*/
		if (d == '\\')
			putchar(getchar()); /*pomiń sekwencję specjalną*/
	}
	putchar(d);	/*wypisz znak kończący stałą*/
}
