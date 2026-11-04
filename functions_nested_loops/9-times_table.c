#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i;
	int j;
	int p;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			p = i * j;
			if (j == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 10)
					_putchar(' ');
				else
					_putchar(p / 10 + '0');
				_putchar(p % 10 + '0');
			}
			j++;
		}
		_putchar('\n');
		i++;
	}
}
