/*
 ============================================================================
 Name        : problem_38.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG_PRINT
#ifdef DEBUG_PRINT
#define debug_print(fmt, args...) printf(fmt,##args)
#else
#define debug_print(fmt, args...)
#endif

#define MAX_NUM 9999
//#define MAX_NUM 10
#define CHAR_2_NUM(c) (c-'0')


int is_pandigital(char num_str[])
{
	int i, len, num_map[10], index;

	memset(num_map, 0, 10 * sizeof(int));
	len = strlen(num_str);

	for (i = 0; i < len; i++)
	{
		index = CHAR_2_NUM(num_str[i]);
		if (num_map[index] || index == 0)
			return 0;

		num_map[index] = 1;
	}

	return 1;
}

void make_concatened_str(int num, int n, char num_str[])
{
	int i, index = 0;

	for (i = 1; i <= n; i++)
	{
		index += sprintf(num_str + index, "%d", i * num);
	}

	debug_print("num:%d, n:%d, concated string: %s\n", num, n, num_str);
}

int calculate(char out_str[])
{
	int i = MAX_NUM, j, num, max, max_i;
	char num_str[40];

	memset(num_str, 0, 40);

	for (i = MAX_NUM; i > 0; i--)
	{
		for (j = 2;; j++)
		{
			memset(num_str, 0, 40);
			make_concatened_str(i, j, num_str);
			if (strlen(num_str) > 9)
				break;

			num = atoi(num_str);
			if (is_pandigital(num_str) && strlen(num_str) == 9 && max < num)
			{
				max = num;
				max_i = i;
				strcpy(out_str, num_str);
			}
		}
	}

	return max_i;
}

int main(void) {
	char out_str[10];
	//int num = 0;
	time_t start_time, end_time;

	time(&start_time);
	puts("Hello World"); /* prints Hello World */
	memset(out_str, 0, 10);
	//num = calculate(out_str);

	printf("max num = %d, concatened:%s\n", calculate(out_str), out_str);
	time(&end_time);

	printf("")
	return EXIT_SUCCESS;
}
