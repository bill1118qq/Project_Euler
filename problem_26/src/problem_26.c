/*
 ============================================================================
 Name        : problem_26.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT(x) ((x) ? 0 : (x) - '0')
#define CHAR(x) ((x) + '0')
#define STR_LEN 300

int check_the_overlap(char num_str[])
{
	int i, j, len, count = 0;
	char tmp[STR_LEN];

	memset(tmp, 0, STR_LEN);
	tmp[0] = num_str[0];
	for (i = 0; i < strlen(tmp); i++)
	{
		len = strlen(tmp);
		if (len * 3 > STR_LEN)
		{
			count = STR_LEN;
			break;
		}
		for (j = 0; j < len; j++)
		{
			if (!strncmp(tmp + len - j - 1, num_str + len, j + 1) &&
					!strncmp(num_str + len, num_str + len + j + 1, j + 1))
				return count;
		}

		tmp[len] = num_str[len];
		count++;
	}


	return count;
}

void calculate(void)
{
	int i, j, left = 1, longest = 0, longest_num, len;
	char *num_str, tmp[STR_LEN];

	num_str = malloc(1000 * STR_LEN);
	memset(num_str, 0 ,STR_LEN * 1000);
	for (i = 2; i < 1000; i++)
	{
		left = 1;
		for (j = 0; j < STR_LEN; j++)
		{
			left *= 10;
			*(num_str + STR_LEN * i + j) = CHAR(left / i);
			left %= i;
			if (!left)
				break;
		}
		len = check_the_overlap(num_str + STR_LEN * i);
		if (longest < len)
		{
			memcpy(tmp, (num_str + STR_LEN * i), STR_LEN);
			longest_num = i;
			longest = len;
		}
		printf("%d: num_str->%s\n",i, num_str + STR_LEN * i);
	}

	printf("num:%d, count:%d, the longest is:%s", longest_num, longest, tmp);
	return;
}


int main(void) {
	puts("Hello World"); /* prints Hello World */
	calculate();
	return EXIT_SUCCESS;
}
