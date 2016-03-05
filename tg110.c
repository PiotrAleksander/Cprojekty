#include <stdio.h>

/*zastąp znaki tabulacji i cofania czytelnymi sekwencjami*/
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
		if (c != '\b')
			if (c != '\t')
				if (c != '\\')
					putchar(c);
	}
}
