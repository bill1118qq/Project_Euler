/*
 ============================================================================
 Name        : problem_37.c
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

#define DEBUG_PRINT
#ifdef DEBUG_PRINT
#define debug_print(fmt, args...) printf(fmt, ##args);
#else
#define debug_print(fmt, arg...)
#endif

int is_prime(int num)
{
	int i = 0, max_element;
	max_element = (int)sqrt(num);
	debug_print("num = %d, max_element=%d\n", num, max_element);

	if(num <= 1)
		return 0;

	for (i = 2; i <= max_element; i++)
	{
		if (!(num % i))
			return 0;
	}

	return 1;
}

int is_left_to_right_prime(int num)
{
	int i = 0, len;
	char num_str[20];

	memset(num_str, 0, 20);
	itoa(num, num_str, 10);

	len = strlen(num_str);
	for (i = 0; i < len; i++)
	{
		num = atoi(num_str + i);
		if (!is_prime(num))
			return 0;
	}

	return 1;
}

int is_right_to_left_prime(int num)
{
	int i = 0, len;
	char num_str[20];

	memset(num_str, 0, 20);
	itoa(num, num_str, 10);

	len = strlen(num_str);

	for (i = 0; i < len; i++)
	{
		num_str[len - i] = 0;
		num = atoi(num_str);
		if (!is_prime(num))
			return 0;
	}

	return 1;
}

int main(void) {
	int i = 8, count = 0, sum = 0;
	puts("Hello World"); /* prints Hello World */

	while(count < 11)
	{
		if (is_left_to_right_prime(i) && is_right_to_left_prime(i))
		{
			count++;
			sum += i;
			debug_print("num = %d\n", i);
		}
		i++;
	}

	printf("sum = %d, count = %d\n", sum, count);
	return EXIT_SUCCESS;
}
