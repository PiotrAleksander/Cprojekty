/*pierwotna pętla*/
for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;

/*pętla bez logicznych AND i OR*/
enum loop { NO, YES };	 /*czy w pętli NIE, TAK*/
enum loop okloop = YES;

i = 0;
while (okloop == YES)
	if (i >= lim-1)		/*koniec pętli, gdy*/
		okloop = NO;	/*poza poprawnym zakresem*/
	else if ((c = getchar()) == '\n')
		okloop = NO;	/*koniec wiersza*/
	else if (c == EOF)
		okloop = NO;	/*koniec pliku*/
	else {
		s[i] = c;
		++i;
	}
