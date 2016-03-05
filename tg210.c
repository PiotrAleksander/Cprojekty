/*lower: zamień c na małą literę; tylko dla ASCII*/
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
