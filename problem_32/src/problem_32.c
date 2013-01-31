/*
 ============================================================================
 Name        : problem_32.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inline char_2_int(char c)
{
	return (c - '0');
}

int inline pan_digital(int multiplicand, int multiplier)
{
	int product, array_map[10], i, tmp;
	char product_str[5], multiplicand_str[3], multiplier_str[5];

	memset(product_str, 0, 5);
	memset(multiplicand_str, 0, 3);
	memset(multiplier_str, 0, 5);
	memset(array_map, 0, 10 * sizeof(int));

	product = multiplicand * multiplier;
	itoa(product, product_str, 10);
	itoa(multiplicand, multiplicand_str, 10);
	itoa(multiplier, multiplier_str, 10);
	array_map[0] = 1;
	//printf("%d * %d = %d\n", multiplicand, multiplier, product);
	for (i = 0; i < strlen(product_str); i++)
	{
		tmp = char_2_int(product_str[i]);
		if (array_map[tmp] == 0)
		{
			array_map[tmp] = 1;
		}
		else
			return 0;
	}

	for (i = 0; i < strlen(multiplicand_str); i++)
	{
		tmp = char_2_int(multiplicand_str[i]);
		if (array_map[tmp] == 0)
		{
			array_map[tmp] = 1;
		}
		else
			return 0;
	}

	for (i = 0; i < strlen(multiplier_str); i++)
	{
		tmp = char_2_int(multiplier_str[i]);
		if (array_map[tmp] == 0)
		{
			array_map[tmp] = 1;
		}
		else
			return 0;
	}

	printf("%d * %d = %d\n", multiplicand, multiplier, product);
	return product;
}

int is_exist(int array[], int num)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		if (array[i] == num)
		{
			printf("exist: %d\n", num);
			return 1;
		}
	}

	return 0;
}

int calculate(void)
{
	int i, j, total = 0, tmp, tmp_array[10], index = 0;

	memset(tmp_array, 0, 10 * sizeof(int));
	for (i = 1; i < 10; i++)
	{
		for (j = 1234; j < 9999/2; j++)
		{
			tmp = pan_digital(i, j);
			if (tmp && !is_exist(tmp_array, tmp))
			{
				tmp_array[index++] = tmp;
				total += tmp;
			}
		}
	}

	for (i = 12; i <= 98; i++)
	{
		for (j = 123; j <= 987; j++)
		{
			tmp = pan_digital(i, j);
			if (tmp && !is_exist(tmp_array, tmp))
			{
				tmp_array[index++] = tmp;
				total += tmp;
			}
		}
	}

//	if (is_pan_digital(39, 186)) count++;

	return total;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */
	printf("total = %d\n", calculate());
	return EXIT_SUCCESS;
}
