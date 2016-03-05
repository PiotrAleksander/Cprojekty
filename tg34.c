#define abs(x) ((x) < 0 ? -(x) : (x))

/*itoa: zamień liczbę n na znaki w s - wersja zmieniona*/
void itoa(int n, char s[])
{
	int i, sign;
	void reverse(char s[]);

	sign = n;	/*pamiętaj znak liczby n*/
	i = 0;
	do {	/*generuj cyfry w odwrotnym porządku:*/
		s[i++] = abs(n % 10) + '0';	/*weź następną cyfrę*/
	} while ((n /= 10) != 0);		/*usuń ją*/
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
