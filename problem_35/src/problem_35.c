/*
 ============================================================================
 Name        : problem_35.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1000000

int c2i(char c)
{
	return c - '0';
}

int inline is_prime(int n)
{
	int i;

	if (n == 2)
		return 1;

	for (i = 2; i < n; i++)
	{
		if (!(n % i))
			return 0;
	}

	return 1;
}

int is_circulate_prime(int num)
{
	char num_str[8];
	int len, j,i, ch_num, tmp ;

	//printf("\nnum:%d, ", num);
	itoa(num, num_str, 10);
	//printf("num_str:%s\n", num_str);
	len = strlen(num_str);
	for (j = 0; j < len; j++)
	{
		for (i = j, ch_num = 0, tmp = 0; ch_num < len; i = (i + 1) % len, ch_num++)
		{
			tmp *= 10;
			//printf("%d, %c ", tmp, num_str[i]);
			tmp += c2i(num_str[i]);
		}
		//printf("%d ", tmp);
		if (!is_prime(tmp))
			return 0;
	}

	//printf("\n%d is circulate prime========================\n", num);
	return 1;
}

void calculate(void)
{
	int i, count = 0;


	for (i = 2; i <= MAX_NUM; i++)
	{
		if (is_circulate_prime(i))
			count++;
	}

	printf("count = %d\n", count);
}

int main(void) {
	puts("Hello World"); /* prints Hello World */
	calculate();
	return EXIT_SUCCESS;
}
