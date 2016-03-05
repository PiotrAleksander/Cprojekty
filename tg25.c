/*any: podaj pozycję w s1 pierwszego wystąpienia dowolnego znaku z s2*/
int any(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])	/*gdy znaleziono*/
				return i;	/*zwróć pozycję*/
	return -1;	/*gdy nie znaleziono*/
}

