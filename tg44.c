#include <stdio.h>
#include <math.h>

#define MAXOP 100	/*maks. rozmiar argumentu lub operatora*/
#define NUMBER 0	/*sygnał znalezienia liczby*/

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/*kalkulator według Odwrotnej Notacji Polskiej*/
main()
{
	int type;
	double op1, op2;
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
		case '?':	/*wypisz wierzchołek stosu*/
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c':	/*wyczyść stos*/
			clear();
			break;
		case 'd':	/*utwórz na stosie duplikat wierzchołka*/
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':	/*zamień miejscami 2 szczytowe elementy*/
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '\n':	/*pobierz i wypisz wierzchołek stosu*/
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("błąd: nieznane polecenie %s\n", s);
			break;
		}
	}
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/*getop: pobiera następny operator lub operand (liczbę)*/
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/*nie jest liczbą*/
	i = 0;
	if (isdigit(c))		/*pobierz część całkowitą*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*pobierz część ułamkową*/
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];	/*bufor dla ungetch*/
int bufp = 0;		/*następna wolna pozycja w buforze*/

int getch(void)		/*pobiera znak (może być znakiem wcześniej wycofanym)*/
{
	return (bufp > 0) ? buf[--bufp] : getch();
}

void ungetch(int c)	/*wycofuje znak do strumienia danych wejściowych*/
{
	if (bufp >= BUFSIZE)
		printf("ungetch: zbyt wiele znaków\n");
	else
		buf[bufp++] = c;
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
		printf("error: brak miejsca na stosie na %g\n", f);
}

/*pop: zdejmuje i zwraca wartość z wierzchołka stosu*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stos pusty\n");
		return 0.0;
	}
}
/*clear: wyczyść stos*/
void clear(void)
{
	sp = 0;
}
