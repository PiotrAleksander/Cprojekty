/*setbits: wstaw n prawych bitów y do x od pozycji p*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n )) |
	      (y &   ~(~0 << n) << (p + 1 - n);
}
