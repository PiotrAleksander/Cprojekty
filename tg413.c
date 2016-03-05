#include <string.h>

/*reverse: odwróć kolejność znaków tekstu w s*/
void reverse(char s[])
{
	void reverser(char s[], int i, int len);

	reverser(s, 0, strlen(s));
}

/*reverser: zamień miejscami znaki tekstu w s; rekurencja*/
void reverser(char s[], int i, int len)
{
	int c, j;

	j = len - (i + 1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}
