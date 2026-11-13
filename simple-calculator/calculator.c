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
 * clear_input - discards the rest of the current input line
 *
 * Return: void
 */
void clear_input(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}

/**
 * read_operands - prompts for and reads A and B
 * @a: pointer to store A
 * @b: pointer to store B
 *
 * Return: 1 on success, 0 on failure
 */
int read_operands(int *a, int *b)
{
	printf("A: ");
	if (scanf("%d", a) != 1)
	{
		clear_input();
		return (0);
	}
	printf("B: ");
	if (scanf("%d", b) != 1)
	{
		clear_input();
		return (0);
	}
	return (1);
}

/**
 * do_operation - runs the operation for a menu choice
 * @choice: the menu choice
 *
 * Return: void
 */
void do_operation(int choice)
{
	int a, b;

	if (choice < 1 || choice > 4)
	{
		printf("Invalid choice\n");
		return;
	}
	if (!read_operands(&a, &b))
	{
		printf("Invalid input\n");
		return;
	}
	if (choice == 1)
		printf("Result: %d\n", a + b);
	else if (choice == 2)
		printf("Result: %d\n", a - b);
}

/**
 * main - simple calculator
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice, r;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		printf("Choice: ");
		r = scanf("%d", &choice);
		if (r == EOF || (r == 1 && choice == 0))
		{
			printf("Bye!\n");
			break;
		}
		if (r != 1)
		{
			clear_input();
			printf("Invalid choice\n");
			continue;
		}
		do_operation(choice);
	}
	return (0);
}
