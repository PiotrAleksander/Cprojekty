/*rightrot: przesuń x cyklicznie w prawo o n pozycji*/
unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);	/*długość słowa maszyny*/
	int rbit;		/*skrajnie prawy bit słowa*/

	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;	/*przesuń x o jedną pozycję w prawo*/
		x = x | rbit;	/*uzupełnij rotację*/
	}
	return x;
}

/*wordlength: oblicz długość słowa maszyny*/
int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}
