/**
 * Exercice - accept an hour value an determine if its fall within office hours and display
 * the appropriate business status message
 */

#include <stdio.h>
#include <string.h>
/**
 * main - Entry
 * Return - success
 */

void main(void)
{
	int hours;

	printf("Entrer the hour: ");
	scanf("%i", &hours);

	if (hours >= 9 && hours <= 17)
	{
		printf("Work time !\n");
	}

	else if (hours >= 0 && hours <= 23)
	{
		printf("Take a rest !\n");
	}

	else
	{
		printf("Wrong numbers !\n");
	}
}
