void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i]) {	/*wstaw:*/
		case '\n':	/*sekwencję znaku nowego wiersza*/
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':	/*sekwencję znaku tabulacji*/
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:	/*skopiuj wszystkie inne znaki*/
			s[j++] = t[i];
			break;
		}
	s[j] = '\0';
}
