/*escape: kopiując tekst z t do s, zamień znaki nowego wiersza
  	  i znaki tabulacji na czytelne sekwencje specjalne*/
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

/*unescape: kopiując tekst z t do s, zamień sekwencje specjalne na
	    rzeczywiste znaki nowego wiersza lub tabulacji*/
void unescape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; t[i] != '\0'; i++)
		if (t[i] != '\\')
			s[j++] = t[i];
		else		/*to backslash - wstaw:*/
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
	s[j] = '\0';
}
