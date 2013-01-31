/*
 ============================================================================
 Name        : problem_19.c
 Author      : Cao Liang
 Version     :
 Copyright   : Anyone can use it for anything
 Description : Hello World in C, Ansi-style

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char week_days[][12] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int month_days[13] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int inline is_leap(int year)
{
	int ret = 0;

	if ((year % 4 == 0 && year % 100) || !(year % 400))
		ret = 1;

	return ret;
}

int week_day_index_by_day(int year, int month, int day)
{
	int i = 0, index;
	int days = 0;
	for (i = 1900; i < year; i++)
	{
		days += 365;
		if (is_leap(i)) days++;
	}

	for (i = 1; i < month; i++)
	{
		days += month_days[i];
		if (i == 2 && is_leap(year)) days++;
	}

	days += day;

	index = days % 7;

	return index;
}

int calculate_Sundays(void)
{
	int i, j, k, count = 0, index;

	for (i = 1901; i <= 2000; i++ )
		for (j = 1; j <= 12; j++)
			for (k = 1; k <= month_days[j]; k++)
				if ( (index = week_day_index_by_day(i, j, k)) == 0 && k == 1)
				{
					count++;
					printf("%d-%d-%d is %s\n", i, 1, j, week_days[index]);
				}

	//week_day_index_by_day(1900,3,31);


	return count;
}

int main(void) {
	puts("Hello World"); /* prints Hello World */


	printf("There are %d Sundays\n", calculate_Sundays() );

	return EXIT_SUCCESS;
}
