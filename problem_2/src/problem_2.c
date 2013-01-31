/*
 ============================================================================
 Name        : problem_2.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int is_even(int num)
{
	return ((num % 2) == 0);
}

int main(void) {
	int prev = 0, next = 1, fib = 0;
	int amount = 0;
	puts("Hello World"); /* prints Hello World */


	while ((next + prev) < 4000000)
	{
		fib = next + prev;
		prev = next;
		next = fib;
		printf("fib = %d\n", fib);
		if (is_even(fib))
		{
			amount += fib;
		}

	}

	printf("amount = %d", amount);
	return EXIT_SUCCESS;
}
