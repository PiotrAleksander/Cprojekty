/*itoa: konwertuje n na ciąg znakowy w s*/
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0) /*zapisz znak*/
		n = -n;	    /*niech n będzie dodatnie*/
	i = 0;
	do {	/*wygeneruj cyfry w odwróconej kolejności*/
		s[i++] = n % 10 + '0'; /*pobierz następną cyfrę*/
	} while ((n /= 10) > 0);	/*usuń cyfrę*/
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

















