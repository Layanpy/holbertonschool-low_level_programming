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
 * main - simple calculator skeleton
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice = 0;

	printf("Simple Calculator\n");
	print_menu();
	printf("Choice: ");
	if (scanf("%d", &choice) != 1)
		choice = 0;
	if (choice == 0)
		printf("Bye!\n");
	return (0);
}
