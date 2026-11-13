#include <stdio.h>

/**
 * print_menu - prints the calculator menu
 *
 * Return: void
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}

/**
 * main - simple calculator with menu loop
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice, r, c;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		printf("Choice: ");
		r = scanf("%d", &choice);
		if (r == EOF)
		{
			printf("Bye!\n");
			break;
		}
		if (r != 1)
		{
			while ((c = getchar()) != '\n' && c != EOF)
				;
			printf("Invalid choice\n");
			continue;
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}
	return (0);
}
