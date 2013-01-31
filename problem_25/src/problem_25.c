/*
 ============================================================================
 Name        : problem_25.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR(x) ((x) + '0')
#define INT(x) (x == 0 ? 0 :((x) - '0'))

void print_num(char str[])
{
	int i;
	printf("the number is:");
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		putchar(str[i]);
	}
	putchar('\n');

	return;
}

int fibonacci(void)
{
	char f1[1001], f2[1001], temp[1001];
	int i, carry_over, tmp_int, term = 2;

	memset(f1, 0, 1001);
	memset(f2, 0, 1001);

	f1[0] = '1', f2[0] = '1';
	while(strlen(f2) < 1000)
	{
		carry_over = 0;
		memset(temp, 0, 1001);
		memcpy(temp, f2, strlen(f2));
		for (i = 0; i < strlen(f2); i++)
		{
			tmp_int = INT(f2[i]) + INT(f1[i]);
			f2[i] = CHAR((tmp_int + carry_over) % 10);
			carry_over = (tmp_int + carry_over) / 10;
		}
		if (carry_over)
			f2[i] = CHAR(carry_over);
	    memcpy(f1, temp, strlen(temp));
	    term++;
	    printf("term = %d, ", term);
	    print_num(f2);
	}

	print_num(f2);
	printf("term = %d, length:%d\n", term, strlen(f2));
	return 0;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */

	fibonacci();
	return EXIT_SUCCESS;
}
