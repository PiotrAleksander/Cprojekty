/*squeeze: usuń z s1 wszystkie znaki występujące w s2*/
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;	/*każdego s1[i] szukaj w s2*/
		if (s2[j] == '\0') /*koniec tekstu s2 - nie znaleziono*/
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}
