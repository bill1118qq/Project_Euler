/*
 ============================================================================
 Name        : problem_18.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node_t {
	int i;
	int j;
}node_t;

typedef struct route_t {
	struct node_t node_array[15];
}route_t;

int read_triangle(int a[][15])
{

	FILE *file_handle;
	char tmp[3];
	int i = 0, j = 0, k = 0;

	file_handle = fopen("triangle.txt", "r");
	if (file_handle == NULL)
		return -1;

	while((tmp[k] = fgetc(file_handle)) != EOF)
	{
		if(isdigit(tmp[0]) && isdigit(tmp[1]))
		{
			a[i][j] = atoi(tmp);
			j++;
			k = 0;
			memset(tmp, 0, 3);
		} else if(tmp[0] == '\n')
		{
			i++;
			j = 0;
		}
		else if (tmp[0] == ' ')
			continue;
		else
			k++;
	}
	return 0;
}

void print_route(struct route_t *route)
{
	int i = 0;

	printf("route:");
	for (i = 0; i < 15; i++)
	{
		printf("[%d][%d] ", route->node_array[i].i, route->node_array[i].j);
	}
	printf("\n");

	return;
}

void trace_route(int triangle[][15], int i, int j, int sum, int *biggest, route_t *route)
{

	route->node_array[i].i = i;
	route->node_array[i].j = j;

	if (i == 14)
	{
		sum += triangle[i][j];
		if (*biggest < sum)
			*biggest = sum;
		printf("sum = %d, i=%d, j=%d, biggest = %d\n", sum, i, j, *biggest);
		print_route(route);
		return;
	}

	trace_route(triangle, i + 1, j, sum + triangle[i][j], biggest, route);
	trace_route(triangle, i + 1, j + 1, sum + triangle[i][j], biggest, route);

	return ;
}

int main(void) {
	int triangle[15][15], biggest = 0;
	route_t route;
	puts("Hello World"); /* prints Hello World */

	memset(triangle, 0, sizeof(int) * 15 * 15);
	read_triangle(triangle);

	trace_route(triangle, 0, 0, 0, &biggest, &route);

	return EXIT_SUCCESS;
}
