/*
 ============================================================================
 Name        : problem_16.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 1000

void calculate(char value[])
{
	int i = 0, j, len, temp, carry_over = 0, left;
	value[0] = '1';
	for (i = 0; i < COUNT; i++)
	{
		len = strlen(value);
		carry_over = 0;
		for (j = len - 1; j >= 0; j--)
		{
			temp = (value[j] - '0')* 2 + carry_over;
			carry_over = temp / 10;
			left = temp % 10;
			value[j] = left + '0';
		}
		if (carry_over)
		{
			for (j = len; j > 0; j--)
			{
				value[j] = value[j - 1];
			}
			value[0] = carry_over + '0';
		}
	}

	printf("%s\n", value);
	return;
}

int sum_all(char value[])
{
	int i = 0, len = strlen(value), ret_val = 0;
	for(i = 0; i < len; i++)
	{
		ret_val += value[i] - '0';
	}
	return ret_val;
}

int main(void) {
	int i = 0;
	char value[1000];
	puts("Hello World"); /* prints Hello World */

	memset(value, 0, 1000);
	calculate(value);

	printf("result is:%s\n", value);

	printf("%d\n", sum_all(value));

	return EXIT_SUCCESS;
}
