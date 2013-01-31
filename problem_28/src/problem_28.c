/*
 ============================================================================
 Name        : problem_28.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 *
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPIRAL_SIZE 1001

void print_spiral(int **a, int size)
{
	int i, j;

	for (i = 0; i < SPIRAL_SIZE; i++)
	{
		for (j = 0; j < SPIRAL_SIZE; j++)
		{
			printf("%10.d", a[i][j]);
		}
		printf("\n");
	}
}

void construct_spiral(int **a)
{
	int i, j, diameter, count = 1, middle_point;


	middle_point = SPIRAL_SIZE / 2;
	a[middle_point][middle_point] = 1;
	i = middle_point;
	j = middle_point + 1;
	for (diameter = 1; diameter <= middle_point; diameter++)
	{
		for (; i < middle_point + diameter; i++) // move down
		{
			a[i][j] = ++count;
		}

		for (; j > middle_point - diameter; j--) // move left
		{
			a[i][j] = ++count;
		}

		for (; i > middle_point - diameter; i--) // move up
		{
			a[i][j] = ++count;
		}

		for (; j <= middle_point + diameter; j++) // move right
		{
			a[i][j] = ++count;
		}
	}

	return;
}

long long calculate_spiral(int **a)
{
	long long i, j, result = 0;

	for (i = 0, j = 0; i < SPIRAL_SIZE; i++, j++)
	{
		result += a[i][j];
		printf("result:%lld, a[%d][%d]:%lld\n", result, i, j, a[i][j]); // This output result has problem
	}

	for (i = SPIRAL_SIZE - 1, j = 0; j < SPIRAL_SIZE; i--, j++)
	{
		result += a[i][j];
		printf("result:%lld, a[%d][%d]:%lld\n", result, i, j, a[i][j]);  // This output result has problem
	}

	return result - 1;
}

int main(void) {
	int **a, i;

	a = malloc(sizeof(int *) * SPIRAL_SIZE);
	for (i = 0; i < SPIRAL_SIZE; i++)
	{
		*(a + i) = malloc(sizeof(int) * SPIRAL_SIZE);
		memset(*(a + i), 0, sizeof(int) * SPIRAL_SIZE);
	}

	construct_spiral(a);
	printf("last result is %lld\n", calculate_spiral(a));
	puts("Hello World"); /* prints Hello World */
	return EXIT_SUCCESS;
}
