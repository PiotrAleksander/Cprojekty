#include <ctype.h>

/*atoi: przekształca ciąg s na liczbę całkowitą; wersja 2*/
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++) /*pomiń białe znaki*/
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /*pomiń znak liczby*/
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
