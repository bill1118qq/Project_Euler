/*
 ============================================================================
 Name        : problem_31.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calculate(void)
{
	int i,j,k,l,m,n,o, count = 0;

	for (i = 0; i <= 200; i++)
		for (j = 0; j <= 100; j++)
			for (k = 0; k <= 40; k++)
				for (l = 0; l <= 20; l++)
					for (m = 0; m <= 10; m++)
						for(n = 0; n <= 4; n++)
							for (o = 0; o <= 2; o++)
							{
								if (i + 2 * j + 5 * k + 10 * l + 20 * m + 50 * n + 100 * o == 200)
								{
									count++;
									//printf("%d*1P + %d*2P + %d*5P + %d*10P + %d*20P + %d*50P + %d*100\n", i,j,k,l,m,n,o);
								}
							}
	return count + 1;  // 200 is also a value.
}

int main(void) {
	puts("Hello World"); /* prints Hello World */

	printf("count = %d\n", calculate());
	return EXIT_SUCCESS;
}
