/**
 * Exercice - read the number of failed login attempts and display the appropriate security status
 */

#include <stdio.h>
#include <string.h>

/**
 * ask_user - function to ask user
 * @entry_user: pointer to entry user
 * Return: store informations
 */
void ask_user(char *entry_user)
{
	printf("Enter your username: ");
	scanf("%s", entry_user);
}


/**
 * main - entry point
 * Return: succes or fail
 */
void main(void)
{
	char entry_user[20];
	char username_ok[] = "Nini";
	int try = 0;

	ask_user(entry_user);

		while (strcmp(entry_user, username_ok) != 0 && try < 3)
		{
			if (try <= 1)
			{
				printf("OK, try again\n");
				printf("Attempt number : %d\n", try + 1);
			}
			else if (try == 2)
			{
				printf("Warning\n");
				printf("Attempt number : %d\n", try + 1);
			}
		ask_user(entry_user);
		try++;
		}

		if (strcmp(entry_user, username_ok) != 0)
		{
			printf("Account locked\n");
		}
		else
		{
			printf("Welcome %s\n", entry_user);
		}
}
