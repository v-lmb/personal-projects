/**
 * Exercice - read a password string and evaluate its strength based on lenght
 */

#include <stdio.h>
#include <string.h>
/**
 * main - Entry
 * Return - success
 */

void main(void)
{
	char password_user[20];

	while (1)
	{
		printf("Enter you password to test (tape 'quit' to exit): ");
		scanf("%s", password_user);

		if (strcmp(password_user, "quit") == 0)
		{
			printf("See you next time !\n");
			break;
		}

		if (strlen(password_user) < 8)
		{
			printf("Your password %s is weak.\n", password_user);
		}

		else if (strlen(password_user) > 12)
		{
			printf("Your password %s is strong.\n", password_user);
		}

		else
		{
			printf("Your password %s is medium.\n", password_user);
		}
	}
}
