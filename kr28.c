/*squeeze: usuwa wszystkie wystąpienia znaku c z ciągu s*/
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

/*strcat: dołącza t na końcu s; rozmiar s musi być wystarczający*/
void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')	/*szukanie końca*/
		i++;
	while ((s[i++] = t[j++]) != '\0') /*kopiowanie*/
		;
}
