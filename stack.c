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
