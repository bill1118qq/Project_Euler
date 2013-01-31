/*
 ============================================================================
 Name        : problem_11.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 Link        : http://projecteuler.net/problem=11
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRING_1 "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08"
#define NUM_STRING_2 "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00"
#define NUM_STRING_3 "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65"
#define NUM_STRING_4 "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91"
#define NUM_STRING_5 "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80"
#define NUM_STRING_6 "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50"
#define NUM_STRING_7 "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70"
#define NUM_STRING_8 "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21"
#define NUM_STRING_9 "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72"
#define NUM_STRING_10 "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95"
#define NUM_STRING_11 "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92"
#define NUM_STRING_12 "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57"
#define NUM_STRING_13 "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58"
#define NUM_STRING_14 "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40"
#define NUM_STRING_15 "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66"
#define NUM_STRING_16 "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69"
#define NUM_STRING_17 "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36"
#define NUM_STRING_18 "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16"
#define NUM_STRING_19 "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54"
#define NUM_STRING_20 "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"


char *number_string(int index)
{
	switch(index)
	{
	case 1:
		return NUM_STRING_1;
	case 2:
		return NUM_STRING_2;
	case 3:
		return NUM_STRING_3;
	case 4:
		return NUM_STRING_4;
	case 5:
		return NUM_STRING_5;
	case 6:
		return NUM_STRING_6;
	case 7:
		return NUM_STRING_7;
	case 8:
		return NUM_STRING_8;
	case 9:
		return NUM_STRING_9;
	case 10:
		return NUM_STRING_10;
	case 11:
		return NUM_STRING_11;
	case 12:
		return NUM_STRING_12;
	case 13:
		return NUM_STRING_13;
	case 14:
		return NUM_STRING_14;
	case 15:
		return NUM_STRING_15;
	case 16:
		return NUM_STRING_16;
	case 17:
		return NUM_STRING_17;
	case 18:
		return NUM_STRING_18;
	case 19:
		return NUM_STRING_19;
	case 20:
		return NUM_STRING_20;
	default:
		return 0;

	}
}

int inline value_from_string_with_index(char *string, int index)
{
	char num_str[3];

	//num_str[2] = '\0';
	memset(num_str, 0, 3);
	if (index < 20)
		memcpy(num_str, (string + index * 3), 2);
	else
		printf("value_from_string_with_index invalid index:%d\n", index);

	return atoi(num_str);
}

void inline init_input_matrix(int a[][20])
{
	int i = 0, j = 0;;

	for (i = 1; i <= 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			a[i-1][j] = value_from_string_with_index(number_string(i), j);
			printf("%d ", a[i-1][j]);
		}
		printf("\n");
	}
	return;
}

int check_row(int a[][20])
{
	int i, j, biggest = 0, product = 0;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20 - 3; j++)
		{
			product = a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3];
			if (product > biggest)
				biggest = product;
		}
	}

	printf("check_row, biggest:%d\n", biggest);
	return biggest;
}

int check_column(int a[][20])
{
	int i, j, biggest = 0, product = 0;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20 - 3; j++)

		{
			product = a[j][i] * a[j+1][i] * a[j+2][i] * a[j+3][i];
			if (product > biggest)
				biggest = product;
		}
	}

	printf("check_column, biggest:%d\n", biggest);
	return biggest;
}

int check_diagonal_left_to_right(int a[][20])
{
	int i, j, biggest = 0, product = 0;

	for (i = 0; i < 20 - 3; i++)
	{
		for (j = 0; j < 20 - 3; j++)
		{
			product = a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];
			printf("[%d,%d][%d,%d][%d,%d][%d,%d],product:%d\n", i,j, i+1,j+1, i+2,j+2, i+3,j+3, product);
			if (product > biggest)
				biggest = product;
		}
	}

	printf("check_diagonal_left_to_right, biggest:%d\n", biggest);
	return biggest;
}

int check_diagonal_right_to_left(int a[][20])
{
	int i, j, biggest = 0, product = 0;

	for (i = 19; i > 2; i--)
	{
		for (j = 0; j < 20 - 3; j++)
		{
			product = a[i][j] * a[i-1][j+1] * a[i-2][j+2] * a[i-3][j+3];
			printf("[%d,%d][%d,%d][%d,%d][%d,%d],product:%d\n", i,j, i-1,j+1, i-2,j+2, i-3,j+3, product);
			if (product > biggest)
				biggest = product;
		}
	}

	printf("check_diagonal_right_to_left, biggest:%d\n", biggest);
	return biggest;
}

int main(void) {
	int a[20][20];
	int biggest = 0, product;
	puts("Hello World"); /* prints Hello World */
	init_input_matrix(a);

	product = check_row(a);
	if (biggest < product)
		biggest = product;

	product = check_column(a);
	if (biggest < product)
		biggest = product;

	product = check_diagonal_left_to_right(a);
	if (biggest < product)
		biggest = product;

	product = check_diagonal_right_to_left(a);
		if (biggest < product)
			biggest = product;

	printf("biggest = %d\n", biggest);
	return EXIT_SUCCESS;
}
