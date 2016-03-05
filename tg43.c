#include <stdio.h>
#include <stdlib.h>	/*dla atof()*/
#include <math.h>	/*dla fmod()*/

#define MAXOP 100	/*maks. rozmiar argumentu lub operatora*/
#define NUMBER '0'	/*sygnał znalezienia liczby*/

int getop(char[]);
void push(double);
double pop(void);

/*kalkulator według Odwrotnej Notacji Polskiej*/
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("błąd: dzielenie przez zero\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("błąd: dzielenie przez zero\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("błąd: nieznane polecenie %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100	/*dopuszczalna głębokość stosu wartości*/

int sp = 0;		/*następna wolna pozycja stosu*/
double val[MAXVAL];	/*stos*/

/*push: zapisuje f na stosie*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("błąd: stos przepełniony, nie można zapisać %g\n", f);
}

/*pop: zdejmuje i zwraca wartość s z wierzchołka stosu*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("błąd: stos pusty\n");
		return 0.0;
	}
}

#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/*getop: pobierz następny operator lub liczbę*/
int getop (char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/*to nie liczba; to operator*/
	if (c == '-')
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;	/*liczba ujemna*/
		else {
			if (c != EOF)
				ungetch(c);
			return '-';	/*znak minus*/
		}
	if (isdigit(c))		/*buduj część całkowitą*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*buduj część ułamkową*/
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;		/*to liczba*/
}

#define BUFSIZE 100

char buf[BUFSIZE];	/*bufor dla ungetch*/
int bufp = 0;		/*następna wolna pozycja w buforze*/

int getch(void)		/*pobiera znak (może być znakiem wcześniej wycofanym*/
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/*wycofuje znak do strumienia danych wejściowych*/
{
	if (bufp >= BUFSIZE)
		printf("ungetch: zbyt wiele znaków\n");
	else
		buf[bufp++] = c;
}

