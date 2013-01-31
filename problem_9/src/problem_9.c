/*
 ============================================================================
 Name        : problem_9.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 0, b = 0, c = 0;
	puts("Hello World"); /* prints Hello World */

	for (a = 0; a < 333; a++)
	{
		b = (1000 * 1000 - 2*a) / (2 - 2*a);
		if (b > 500) continue;
		c = 1000 - a - b;
		if ((a * a + b * b == c * c) && a < b && b < c)
			break;
		printf("a=%d, b=%d, c=%d\n", a, b, c);
	}

	printf("amount = %d", a * b *c);
	return EXIT_SUCCESS;
}
