/*
 ============================================================================
 Name        : problem_40.c
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
#define debug_print(fmt, args...) printf(fmt, ##args)
#else
#define debug_print(fmt, args...)
#endif

int calculate_num(int index)
{
	int i = 0, tmp = 0, left_num, count = 0, bit = 0, num;
	char num_str[7];

	memset(num_str, 0, 7);
	tmp = index;
	while(tmp > 0)
	{
		i++;
		left_num = tmp;
		tmp = tmp - 9 * pow(10, i-1) * i;
	}

	//0.123456789101112131415161718192021...
	count = left_num / i;
	bit   = left_num % i;

	if (bit == 0 && count == 0)
	{
		bit = i - 1;
	}
	else if (bit == 0 && count != 0)
	{
		count -= 1;
		bit = i - 1;
	}
	else if (bit != 0 && count == 0)
	{
		bit  = bit - 1;
	}
	else if (bit != 0 && count != 0)
	{
		bit -= 1;
		//count -= 1;
	}


	num = pow(10, i-1) + count;
	debug_print("num=%d\n", num);
	itoa(num, num_str, 10);

	return (num_str[bit] - '0');
}


int main(void) {
	//printf("11:%d\n", calculate_num(11));
	//printf("12:%d\n", calculate_num(12));
	//printf("17:%d\n", calculate_num(17));
	//printf("15:%d\n", calculate_num(15));
	puts("Hello World"); /* prints Hello World */

	printf("amount = %d\n", calculate_num(1) * calculate_num(10) * calculate_num(100) * calculate_num(1000) * calculate_num(10000) * calculate_num(100000));
	return EXIT_SUCCESS;
}
