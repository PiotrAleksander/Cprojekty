/*unescape: kopiując tekst z t do s, zamień sekwencje specjalne na
	    rzeczywiste znaki nowego wiersza lub tabulacji*/
void unescape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i]) {
		case '\\':	/*to backslash - wstaw:*/
			switch (t[++i]) {
			case 'n':	/*rzeczywisty znak nowego wiersza*/
				s[j++] = '\n';
				break;
			case 't':	/*rzeczywisty znak tabulacji*/
				s[j++] = '\t';
				break;
			default:	/*skopiuj wszystkie inne znaki*/
				s[j++] = '\\';
				s[j++] = t[i];
				break;
			}
			break;
		default:	/*to nie backslash*/
			s[j++] = t[i];	/*skopiuj znak*/
			break;
		}
	s[j] = '\0';
}
