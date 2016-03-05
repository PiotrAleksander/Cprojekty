#define YES 1
#define NO 0

/*htoi: przekształć ciąg cyfr szesnastkowych z s na liczbę całkowitą*/
int htoi(char s[])
{
	int i, n;
	int inhex;	/*to liczba szesnastkowa*/
	int hexdigit;	/*wartość cyfry szesnastkowej*/

	i = 0;
	if (s[i] == '0') {	/*pomiń opcjonalne 0x lub 0X*/
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;	/*obliczana wartość całkowita*/
	inhex = YES;	/*załóżmy, że to poprawna liczba*/
	for ( ; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;	/*to nie jest cyfra szesnastkowa*/
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}
