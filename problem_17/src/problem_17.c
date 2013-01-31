/*
 ============================================================================
 Name        : problem_17.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char in_10_map[][10] = {
	"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

static char below_20_map[][10] = {
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

static char over_20_map[][10] = {
	"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

int extract_to_string(int number, char num_str[])
{
	int temp = 0, index = 0;

	if (number > 1000 || number < 1)
	{
		printf("wrong number\n");
		goto end;
	}

	if ((number / 1000) && !(number % 1000))
	{
		strcpy(num_str, "onethousand");
		goto end;
	}

	temp = number / 100;
	if (temp && !(number % 100))
	{
		strcpy(num_str, in_10_map[temp - 1]);
		index = strlen(in_10_map[temp - 1]);
		strcpy(num_str + index, "hundred");
		goto end;
	}

	temp = number / 100;
	if (temp)
	{
		strcpy(num_str, in_10_map[temp - 1]);
		index += strlen(in_10_map[temp - 1]);
		strcpy(num_str + index, "hundredand");
		index += strlen("hundredand");
	}

	temp = number % 100 / 10;
	if (temp == 1)
	{
		strcpy(num_str + index, below_20_map[number % 10]);
		goto end;
	}
	else if (temp)
	{
		strcpy(num_str + index, over_20_map[temp - 2]);
		index += strlen(over_20_map[temp - 2]);
	}

	if (temp = number % 10)
		strcpy(num_str + index, in_10_map[temp - 1]);

end:
	printf("num_str: %s\n", num_str);
	return strlen(num_str);
}

int main(void) {
	int i = 0;
	int count = 0;
	char num_str[100];
	puts("Hello World"); /* prints Hello World */


	for (i = 1; i <= 1000; i++)
	{
		memset(num_str, 0, 100);
		count += extract_to_string(i, num_str);
	}

	printf("count = %d\n", count);
	return EXIT_SUCCESS;
}
