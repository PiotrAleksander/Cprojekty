/*itob: zamień liczbę n na postać znakową o podstawie b i zapisz do tablicy s*/
void itob(int n, char s[], int b)
{
	int i, j, sign;
	void reverse(char s[]);
	
	if ((sign = n) < 0)	/*zapamiętaj znak liczby*/
		n = -n;		/*n niech będzie dodatnia*/
	i = 0;
	do {	/*generuj cyfry w odwrotnym porządku:*/
		j = n % b;	/*weź następną cyfrę*/
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
	} while ((n /= b) > 0);	/*usuń ją*/
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);	/*odwróć kolejność cyfr w s*/
}
