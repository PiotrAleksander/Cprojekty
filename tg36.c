#define abs(x)	((x) < 0 ? -(x) : (x))

/*itoa: zamień liczbę n na znaki w s, w niech będzie rozmiarem pola*/
void itoa(int n, char s[], int w)
{
	int i, sign;
	void reverse(char s[]);

	sign = n;	/*zapamiętaj znak liczby n*/
	i = 0;
	do {		/*generuj cyfry w odwrotnym porządku*/
		s[i++] = abs(n % 10) + '0'; /*weź następną cyfrę*/
	} while ((n /= 10) != 0);	/*usuń ją*/
	if (sign < 0)
		s[i++] = '-';	/*n była ujemna*/
	while (i < w)
		s[i++] = ' ';	/*dopełnij pole do w pozycji*/
	s[i] = '\0';
	reverse(s);	/*odwróć kolejność cyfr w s*/
}
