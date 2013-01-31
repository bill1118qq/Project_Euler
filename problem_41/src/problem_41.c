/*
 ============================================================================
 Name        : problem_41.c
 Author      : Cao Liang
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define TST_SORT
#define DEBUG_PRINT
#ifdef DEBUG_PRINT
#define debug_print(fmt,args...) printf(fmt,##args)
#else
#define debug_print(fmt, args...)
#endif

int is_prime(int num)
{
	int max_i = 0, i;

	if (num < 2)
		return 0;

	max_i = sqrt(num);
	debug_print("max_i:%d ", max_i);
	for (i = 2; i < max_i; i++)
	{
		if (num % i == 0)
		{
			debug_print("%d is not prime\n", num);
			return 0;
		}
	}

	debug_print("%d is prime, ", i);
	return 1;
}


int is_padinal(int num)
{
	char num_str[10];
	int i, map[10], len, index;

	memset(num_str, 0, 10);
	memset(map, 0, sizeof(int)*10);
	sprintf(num_str, "%d", num);
	len = strlen(num_str);

	for (i = 0; i < len; i++)
	{
		index = num_str[i] - '0';
		if (map[index] || index == 0)
		{
			debug_print("not a padinal\n");
			return 0;
		}
		else
		{
			map[index] = 1;
		}
	}

	debug_print("is a padinal\n");
	return 1;
}


void quick_sort(int num_array[], int left, int right)
{
	int i, j, tmp, key;

	key = i = left;
	j = right;
	while (i < j)
	{
		do{
			if (num_array[i] > num_array[j])
			{
				tmp = num_array[i];
				num_array[i] = num_array[j];
				num_array[j] = tmp;
				key = j;
				j--;
				break;
			}
			j--;
		}while(i < j);


		do {
			if (num_array[i] > num_array[j])
			{
				tmp = num_array[i];
				num_array[i] = num_array[j];
				num_array[j] = tmp;
				key = i;
				i++;
				break;
			}
			i++;
		} while(i < j);
	}

	quick_sort(num_array, left, key - 1);
	quick_sort(num_array, key + 1, right);


}

#define C2N(c) (c - '0')
#define N2C(n) (n + '0')
int next_num(int num)
{
	char num_str[10];
	int index, len, i, least_idx, least_num;
	int num_array[9], tmp;

	memset(num_str, 0, 10);
	sprintf(num_str, "%d", num);

	len = strlen(num_str);

	for (i = 0; i < len; i++)
	{
		num_array[i] = C2N(num_str[i]);
	}

	for (i = 0; i < len - 1; i++)
	{
		if (num_array[i] < num_array[i + 1])
			index = i;
	}


	for (i = index + 1, least_num = 9; i < len; i++)
	{
		if (num_array[i] < least_num && num_array[i] > num_array[index])
		{
			least_idx = i;
			least_num = num_array[i];
		}
	}
	tmp = num_array[index];
	num_array[index] = num_array[least_idx];
	num_array[least_idx] = tmp;

	quick_sort(num_array, index + 1, len - 1);

	for (i = 0; i < len; i++)
	{
		num_str[i] = N2C(num_array[i]);
	}

	return atoi(num_str);
}

int max_prime_padinal(void)
{
	int i = 0, max_padinal = 0;
	for (i = 987654321; i > 2 ; i--)
	{
		if (is_prime(i) && is_padinal(i))
		{
			debug_print("==================== %d ==============================\n", i);
			max_padinal = i;
			break;
		}
	}

	return max_padinal;
}

#ifdef TST_SORT
void test_quick_sort(void)
{
	int quick_sort_array[] = {9,8,7,6,5,4,3,2,1};
	int i;

	quick_sort(quick_sort_array, 0, 8);

	debug_print("quick sort test:");
	for (i = 0; i < 9; i++)
	{
		debug_print("%d ", quick_sort_array[i]);
	}

}
#endif

int main(void) {



#ifdef TST_SORT
	test_quick_sort();
#endif


	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//printf("max prime padinal : %d\n", max_prime_padinal());
	return EXIT_SUCCESS;
}
