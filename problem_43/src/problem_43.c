/*
 ============================================================================
 Name        : problem_43.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG_PRINT
#ifdef DEBUG_PRINT
#define debug_print(fmt, args...) printf(fmt,##args)
#else
//#define debug_print(fmt, args...)
#endif

#define DEBUG_FILE
#ifdef DEBUG_FILE
#define debug_print(file,fmt,args...) fprintf(file,fmt,##args)
#endif

#define SWAP(i,j,tmp) {\
	tmp = i;\
	i = j;\
	j = tmp;\
}

#define LOG_FILE_PATH "./log_file.log"

void quick_sort(int array[], int left, int right)
{
	int i, j, pivot, tmp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = array[i];

		do {
			do {
				i++;
			} while(pivot > array[i] && i <= right);

			do {
				j--;
			} while(pivot < array[j] && j >= left);

			if (i < j)
				SWAP(array[i], array[j], tmp);
		}while(i < j);

		SWAP(array[left], array[j], tmp);
		quick_sort(array, left, j - 1);
		quick_sort(array, j + 1, right);
	}

}


void calculate_next_num_str(char num_str[])
{
	int i, len, key_idx, least_key_idx, least_key = 9, tmp;
	int num_array[10];

	len = strlen(num_str);

	for (i = 0; i < len; i++)
		num_array[i] = num_str[i] - '0';

	for (i = len - 1; i > 0; i--)
		if (num_array[i] > num_array[i - 1])
		{
			key_idx = i - 1;
			break;
		}

	for (i = len - 1; i > key_idx; i--)
		if (num_array[i] <= least_key && num_array[i] > num_array[key_idx])
		{
			least_key_idx = i;
			least_key = num_array[i];
		}

	SWAP(num_array[key_idx], num_array[least_key_idx], tmp);
	quick_sort(num_array, key_idx + 1, len - 1);

	for (i = 0; i < len; i++)
		num_str[i] = num_array[i] + '0';
}

int is_padinal(char num_str[])
{
	int num;
	char sub_num_str[4];
/*
	if (num_str[0] == '2')
		debug_print("break here\n");
*/
	sub_num_str[3] = '\0';
	memcpy(sub_num_str, &num_str[1], 3);
	num = atoi(sub_num_str);
	if (num % 2)
		return 0;

	memcpy(sub_num_str, &num_str[2], 3);
	num = atoi(sub_num_str);
	if (num % 3)
		return 0;

	memcpy(sub_num_str, &num_str[3], 3);
	num = atoi(sub_num_str);
	if (num % 5)
		return 0;

	memcpy(sub_num_str, &num_str[4], 3);
	num = atoi(sub_num_str);
	if (num % 7)
		return 0;

	memcpy(sub_num_str, &num_str[5], 3);
	num = atoi(sub_num_str);
	if (num % 11)
		return 0;

	memcpy(sub_num_str, &num_str[6], 3);
	num = atoi(sub_num_str);
	if (num % 13)
		return 0;

	memcpy(sub_num_str, &num_str[7], 3);
	num = atoi(sub_num_str);
	if (num % 17)
		return 0;

	return 1;

}

long long calculate_all_padinal(void)
{
	char num_str[] = "0123456789";
	long long value = 0, tmp;
	char all_num_str[30][11];
	int i = 0, j;

	FILE *fp;

	fp = fopen(LOG_FILE_PATH, "w+");

	memset(all_num_str, 0, 30 * 11);
	do {
		debug_print(fp, "num = %s\n", num_str);
		if (is_padinal(num_str))
		{
			debug_print(fp, "%s is padinal\n", num_str);
			memcpy(all_num_str[i], num_str, 10);
			i++;
			tmp = atoll(num_str);
			debug_print(fp, "tmp is %lld\n", tmp);
			value += atoll(num_str);;
			debug_print(fp, "value is:%lld\n", value);
		}
		calculate_next_num_str(num_str);
	} while (strcmp(num_str, "9876543210"));

	if (is_padinal(num_str))
		value += atoi(num_str);

	for (j = 0; j < i; j++)
	{
		debug_print(fp, "pandinal num = %s\n", all_num_str[i]);
	}

	return value;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */
	printf("value=%lld\n", calculate_all_padinal());
	return EXIT_SUCCESS;
}
