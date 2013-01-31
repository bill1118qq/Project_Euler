/*
 ============================================================================
 Name        : problem_20.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INT(c) ((c) - '0')
#define CHAR(i) ((i) + '0')

int inline num_bit(int num)
{
	int i = 1, count = 0;

	for(i = 1; (num / i) != 0; i *= 10)
		count++;

	return count;
}

int calculate(void)
{
	int i = 0, j = 0, k = 0, carry_over, temp, len;
	char result[200], c, adder[3][200];

	memset(result, 0, 200);

	result[0] = '1';
	for (i = 1; i <= 100; i++)
	{
		for (k = 0; k < num_bit(i); k++)
		{
			memset(adder[k], 0, 200);
			adder[k][0] = '0';
			adder[k][1] = '0';
		}

		for (k = 0; k < num_bit(i); k++)
		{
			carry_over = 0;
			len = strlen(result);
			temp = (int)(i / pow(10, k)) % 10;
			for (j = k; j < len + k; j++)
			{
				c = result[j - k];
				temp = temp * INT(c) + carry_over;
				adder[k][j] = CHAR(temp % 10);
				carry_over = temp / 10;
			}
		}

		len = 0;
		for (k = 0; k < num_bit(i); k++)
		{
			if (len < strlen(adder[k]))
				len = strlen(adder[k]);
		}

		carry_over = 0;
		for (j = 0; j < len; j++)
		{
			temp = 0;
			for (k = 0; k < num_bit(i); k++)
			{
				temp = INT(adder[k][j]) + temp;
			}
			temp += carry_over;
			result[j] = CHAR(temp % 10);
			carry_over = temp / 10;
		}
		if (carry_over)
			result[j] = CHAR(carry_over);

		printf("%d! = %s\n", i, result);
	}

	return 0;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */
	calculate();
	return EXIT_SUCCESS;
}
