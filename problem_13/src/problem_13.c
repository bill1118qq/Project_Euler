/*
 ============================================================================
 Name        : problem_13.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void handle_carray_over(char sum[], int carry_over)
{
	int i, j, idx, len, temp;

	len = strlen(sum);
	idx = len - 50;

	while(carry_over && idx > 0)
	{
		temp = sum[idx - 1] - '0' + 1;
		carry_over = temp / 10;
		sum[idx - 1] = temp % 10 + '0';
		idx--;
	}

	if (carry_over)
	{
		for (i = len; i > 0; i--)
		{
			sum[i] = sum[i-1];
		}
		sum[i] = '1';
	}

	return;

}

void calculate(char path[])
{
	FILE *file_handle;
	char c;
	char array[100][50];
	char sum[500];
	int i = 0, j = 0, carry_over = 0, temp, len = 0;

	file_handle = fopen(path, "rt");
	memset(sum, 0, 500);
	while((c = fgetc(file_handle)) != EOF)
	{
		if (isdigit(c))
		{
			array[i][j] = c;
			j++;
		}
		if (j >= 50)
		{
			j = 0;
			i++;
		}
	}

	for (i = 0; i < 50; i++)
	{
		sum[i] = array[0][i];
	}

	for (i = 1; i < 100; i++)
	{
		len = strlen(sum);
		for (j = 1; j <= 50; j++)
		{
			temp = array[i][50 - j] - '0' + sum[len - j] - '0' + carry_over;
			sum[len - j] = temp % 10 + '0';
			carry_over = temp / 10;
		}
		handle_carray_over(sum, carry_over);
		printf("sum = %s, count= %d, len=%d\n\n", sum, i, strlen(sum));
	}

	for (i = 0; i < 10; i++)
		putchar(sum[i]);
}

int main(void) {
	puts("Hello World"); /* prints Hello World */
	calculate("input_file");
	return EXIT_SUCCESS;
}
