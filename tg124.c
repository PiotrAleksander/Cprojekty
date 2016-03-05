#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

/*zbadaj szczątkową poprawność programu w C*/
main()
{
	int c;
	extern int brace, brack, paren;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			if ((c = getchar()) == '*')
				in_comment();	/*początek komentarza*/
			else
				search(c);
		} else if (c == '\'' || c == '"')
			in_quote(c);	/*początek stałej*/
		else
			search(c);

		/*wypisz komunikat o błędzie*/
		if (brace < 0) {
			printf("Niezrównoważone nawiasy klamrowe\n");
			brace = 0;
		} else if (brack < 0) {
			printf("Niezrównoważone nawiasy kwadratowe\n");
			brack = 0;
		} else if (paren < 0) {
			printf("Niezrównoważone nawiasy okrągłe\n");
			paren = 0;
		}
	}
	if (brace > 0)
		printf("Niezrównoważone nawiasy klamrowe\n");
	if (brack > 0)
		printf("Niezrównoważone nawiasy kwadratowe\n");
	if (paren > 0)
		printf("Niezrównoważone nawiasy okrągłe\n");
	return 0;
}

/*search: szukaj elementarnych błędów składniowych*/
void search(int c)
{
	extern int brace, brack, paren;

	if (c == '{')
		++brace;	/*otwierający nawias klamrowy*/
	else if (c == '}')
		--brace;	/*zamykający nawias klamrowy*/
	else if (c == '[')
		++brack;
	else if (c == ']')
		--brack;
	else if (c == '(')
		++paren;
	else if (c == ')')
		--paren;
}

/*in_comment: szukaj końca komentarza*/
void in_comment(void)
{
	int c, d;

	c = getchar();	/*poprzedni znak*/
	d = getchar();	/*bieżący znak*/
	while (c != '*' || d != '/') {	/*szukaj końca*/
		c = d;
		d = getchar();
	}
}

/*in_quote: szukaj końca stałej znakowej lub napisowej*/
void in_quote(int c)
{
	int d;

	while ((d = getchar()) != c)	/*szukaj końca stałej*/
		if (d == '\\')
			getchar();	/*pomiń sekwencję specjalną*/
}
