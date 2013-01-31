/*
 ============================================================================
 Name        : problem_14.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int divide(long num, int num_array[])
{
	long divider = num;
	int count = 1;

	num_array[0] = num;
	while(divider > 1)
	{
		//printf("%ld->", divider);
		if (divider % 2)
			divider = divider * 3 + 1;
		else
			divider /= 2;

		count++;
		num_array[count] = divider;
	}

	//printf("1\n");

	return count;
}

void print_num_array(int num_array[], int count)
{
	int i = 0;
	printf("=============================================================================\n");
	for(i = 0; i < count; i++)
	{
		printf("%d->", num_array[i]);
	}
	printf("\n=============================================================================\n");
}

int main(void) {
	long num, longest_num = 0;
	int count = 0, longest_count = 0;
	time_t start_time, end_time;
	int num_array[1000];
	puts("Hello World"); /* prints Hello World */

	time(&start_time);
	for (num = 0; num < 1000000; num++)
	{
		//printf("\n\n");
		count = divide(num, num_array);
		//printf("------------------------------------------------------------------------------------\n");
		if (longest_count < count)
		{
			longest_count = count;
			longest_num = num;
		}
		//printf("num = %ld, count=%d, longest:%ld, longest_count=%d\n", num, count, longest_num, longest_count);
		//printf("========================================================================================\n");
		divide(longest_num, num_array);
		//printf("========================================================================================\n");
		//print_num_array(num_array, longest_count);
	}

	time(&end_time);

	printf("num = %ld, count=%d, longest:%ld, longest_count=%d\n\n", num, count, longest_num, longest_count);
	printf("num = %ld, time:%lf\n", longest_num, difftime(end_time, start_time));

	return EXIT_SUCCESS;
}
