#include <math.h>

/*itoa: przekształć n na znaki w s; wersja rekurencyjna*/
void itoa(int n, char s[])
{
	static int i;

	if (n / 10)	/*to prawda dla n / 10 != 0*/
		itoa(n / 10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}
