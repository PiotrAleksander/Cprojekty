/*bitcount: policz bity 1 w x - szybsza wersja*/
int bitcount(unsigned x)
{
	int b;

	for(b = 0; x != 0; x &= x - 1)
		++b;
	return b;
}
