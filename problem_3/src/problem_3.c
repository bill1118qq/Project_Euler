/*
 ============================================================================
 Name        : problem_3.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 0;
	int num = 1;
	int got = 0;
	int divider[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	puts("Hello World"); /* prints Hello World */
	while (!got)
	{
		for (i = 0; i < 10; i++)
		{
			if (num % divider[i])
				break;
		}
		if (i == 10) {got = 1; break;}
		num++;
	}

	printf ("num = %d", num);
	return EXIT_SUCCESS;
}
