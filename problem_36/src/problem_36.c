/*
 ============================================================================
 Name        : problem_36.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inline is_palindromic(int num, int radix)
{
	int ret = 1, i, len = 0;
	char num_str[21];

	memset(num_str, 0, 21);
	itoa(num, num_str, radix);
	len = strlen(num_str);

	for(i = 0; i < len / 2; i++)
	{
		if (num_str[i] != num_str[len - i - 1])
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

int is_2_palindromic(int num)
{
	return is_palindromic(num, 2);
}

int is_10_palindromic(int num)
{
	return is_palindromic(num, 10);
}

int main(void) {
	int i = 0, count = 0, sum = 0;
	puts("Hello World"); /* prints Hello World */

	for (i = 0; i < 1000000; i++)
	{
		if (is_2_palindromic(i) && is_10_palindromic(i))
		{
			count++;
			sum += i;
			printf("num= %d\n", i);
		}
	}

	printf("sum = %d, count = %d\n", sum, count);
	return EXIT_SUCCESS;
}
