/*
 ============================================================================
 Name        : problem_21.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START 1

int calculate(void)
{
	int pairs[10001], i, j, val = 0;

	memset(pairs, 0, 10001 * sizeof(int));

	for (i = START; i <= 10000; i++)
	{
		printf("%d: ", i);
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				printf("%d ", j);
				pairs[i] += j;
			}
		}
		printf("\n");
	}

	for (i = START; i < 10001; i++)
	{
		//printf("pairs[%d] = %d\n", i, pairs[i]);
		if (pairs[i] < 10001 && i == pairs[pairs[i]] && i < pairs[i] )
		{
			printf("pair: %d & %d\n", i, pairs[i]);
			val += i + pairs[i];
		}
	}

	return val;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */

	printf("count= %d\n", calculate());
	return EXIT_SUCCESS;
}
