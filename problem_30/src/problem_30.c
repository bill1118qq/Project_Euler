/*
 ============================================================================
 Name        : problem_30.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define CHAR_2_NUM(x) ((x) - '0')
#define NUM_2_CHAR(x) ((x) + '0')

int inline fifth_power(int integer_num)
{
	char num_str[6];
	int i, total_num = 0, len;

	memset(num_str, 0, 6);
	itoa(integer_num, num_str, 10);
	len = strlen(num_str);

	for (i = 0; i < len; i++)
	{
		total_num += pow(CHAR_2_NUM(num_str[i]), 5);
	}

	//printf("%d+%d+%d+%d+%d:", CHAR_2_NUM(num[0]), CHAR_2_NUM(num[1]), CHAR_2_NUM(num[2]), CHAR_2_NUM(num[3]), CHAR_2_NUM(num[4]));
	//printf("%d+%d+%d+%d+%d\n", (int)pow(CHAR_2_NUM(num[0]), 5), (int)pow(CHAR_2_NUM(num[1]), 5),
	//		(int)pow(CHAR_2_NUM(num[2]), 5), (int)pow(CHAR_2_NUM(num[3]), 5), (int)pow(CHAR_2_NUM(num[4]), 5));
	return total_num;
}

int calculate(void)
{
	int i, total_num = 0;

	for (i = 2; i < 200000; i++)
	{
		if (i == fifth_power(i))
		{
			total_num += i;
			printf("%d ===============================\n", i);
		}
	}


	return total_num;
}

int main(void) {
	time_t start_time, end_time;
	puts("Hello World"); /* prints Hello World */
	time(&start_time);
	printf("total_num = %d\n", calculate());
	time(&end_time);

	return EXIT_SUCCESS;
}
