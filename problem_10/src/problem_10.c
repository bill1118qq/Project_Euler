/*
 ============================================================================
 Name        : problem_10.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct prime_node_t {
	int value;
	struct prime_node_t *next;
}prime_node_t;

typedef struct prime_list_t {
	int amount;
	struct prime_node_t *head;
	struct prime_node_t *tail;
}prime_list_t;

void init_list(prime_list_t *list)
{
	list->head = list->tail;
	list->amount = 0;
}

int add_to_list(prime_list_t *list, int value)
{
	prime_node_t *node = malloc(sizeof(prime_node_t));

	//printf("prime value:%d\t", value);
	node->value = value;
	node->next = NULL;

	if (list->head == NULL)
	{
		list->head = list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->amount++;

	return list->amount;
}

int main(void) {
	long long i = 0, j;
	long long amount = 0;
	prime_node_t *node;
	prime_list_t list;
	time_t start_time, end_time;

	time(&start_time);
	memset(&list, 0, sizeof(prime_list_t));
	memset(&node, 0, sizeof(prime_node_t));
	init_list(&list);
	puts("Hello World"); /* prints Hello World */

	for (i = 2; i < 2000000; i++)
	{
		node = list.head;
		for(j = 0; j < list.amount; j++)
		{
			if (i % node->value == 0) break;
			node = node->next;
		}

		if (j == list.amount) {
			add_to_list(&list, i);
			amount += i;
		//	printf("amount:%lld\n", amount);
		}
	}
	time(&end_time);

	printf("time:%lf, last value:%d, amount:%lld\n", difftime(start_time, end_time), list.tail->value, amount);
	return EXIT_SUCCESS;
}
