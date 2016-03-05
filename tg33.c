/*expand: rozwiń skrócone zapisy z s1 i zapisz je do s2*/
void expand(char s1[], char s2[])
{
	char c;	
	int i, j;
	
	i = j = 0;
	while ((c = s1[i++]) != '\0')	/*pobierz znak z s1*/
		if (s1[i] == '-' && s1[i+1] >= c) {
			i++;
			while (c < s1[i])	/*rozwiń skrót w s2*/
				s[j++] = c++;
		} else
			s2[j++] = c;	/*wpisz znak do s2*/
	s2[j] = '\0';
}
