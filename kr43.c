#include <stdio.h>
#include <stdlib.h>	/*dla atof()*/

#define MAXOP 100	/*dopuszczalny rozmiar operandu lub operatora*/
#define NUMBER '0'	/*sygnał, że pobrano liczbę*/

int getop(char []);
void push(double);
double pop(void);

/*kalkulator z odwrotną notacją polską*/
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
				printf("error: dzielenie przez zero\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: nieznana komenda %s\n", s);
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
