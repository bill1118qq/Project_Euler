/*
 ============================================================================
 Name        : problem_12.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(void) {

	int i, j, triangle = 0, count;
	time_t start_time, end_time;

	puts("Hello World"); /* prints Hello World */

	time(&start_time);

	for (i = 0;; i++)
	{
		count = 0;
		triangle += i;
		//printf("triangle:%d:", triangle);
		for (j = 1; j <= triangle; j++)
		{
			if(!(triangle % j))
			{
				//printf("%d ", j);
				count++;
			}
		}

		if (count > 500)
			break;

		//printf("count:%d\n", count);
	}

	time(&end_time);

	printf("triangle:%d, time:%d\n", triangle, difftime(end_time, start_time));
	return EXIT_SUCCESS;
}
