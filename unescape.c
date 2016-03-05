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
