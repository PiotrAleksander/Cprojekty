/*invert: zamień n bitów x od pozycji p: 1 na 0 i odwrotnie*/
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}
