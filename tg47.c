#include <string.h>

/*ungets: oddaj na wejście tekst z s*/
void ungets(char s[])
{
	int len = strlen(s);
	void ungetch(int);

	while(len > 0)
		ungetch(s[--len]);
}
