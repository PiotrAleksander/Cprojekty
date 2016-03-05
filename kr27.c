/*atoi: konwersja ciągu znakowego na liczbę całkowitą*/
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <='9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/*lower: konwersja znaku na małe litery; tylko ASCII*/
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

unsigned long int next = 1;

/*rand: zwraca pseudolosową liczbę całkowitą 0..32767*/
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

/*srand: inicjalizacja rand()*/
void srand(unsigned int seed)
{
	next = seed;
}
