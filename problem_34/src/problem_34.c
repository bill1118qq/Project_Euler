/*
 ============================================================================
 Name        : problem_34.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 2540160  //9! * 7


int inline char_2_int(char c)
{
	return c - '0';
}

int calculate_fractions(int n)
{
	if (n == 1)
		return 1;

	return n * calculate_fractions(n - 1);
}

void fill_fractions(int a[])
{
	int i = 0;
	for(i = 1; i < 10; i++)
	{
		a[i] = calculate_fractions(i);
	}
}

int is_fraction_curious(int num, int fraction_array[])
{
	char num_str[8];
	int i, len;
	int sum = 0;

	memset(num_str, 0, 8);
	itoa(num, num_str, 10);
	len = strlen(num_str);
	for (i = 0; i < len; i++)
	{
		sum += fraction_array[char_2_int(num_str[i])];
	}

	if (sum == num)
		return 1;

	return 0;
}

void calculate(void)
{
	int fraction_array[10], i, sum = 0;

	fill_fractions(fraction_array);

	for (i = 3; i < 2540160; i++)
	{
		if (is_fraction_curious(i, fraction_array))
		{
			sum += i;
		}
	}

	printf("sum = %d", sum);
}

int main(void) {

	puts("Hello World"); /* prints Hello World */

	calculate();

	return EXIT_SUCCESS;
}
