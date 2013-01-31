/*
 ============================================================================
 Name        : problem_7.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int prime_array[10001];
	int index = 0, num = 2, i;
	memset(prime_array, 0, sizeof(int) * 10001);
	puts("Hello World"); /* prints Hello World */

	while(index < 10001)
	{
		for(i = 0; i < index; i++)
		{
			if (!(num % prime_array[i]))
				break;
		}
		if (i == index) {prime_array[index] = num; index++; printf("num = %d\t", num);}
		num++;
	}

	printf("prime:%d\n", prime_array[10000]);

	return EXIT_SUCCESS;
}
