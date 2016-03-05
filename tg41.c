/*strrindex: podaj pozycję ostatniego teksttu t w s lub -1*/
int strrindex(char s[], char t[])
{
	int i, j, pos;

	pos = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}
