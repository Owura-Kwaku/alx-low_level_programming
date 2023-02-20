#include <stdio.h>
/**
 * main - prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, m;

	for (n = 48; n < 9; n++)
	{
		for (m = n + 1; m < 10; m++)
		{
			putchar((n % 10) + '0');
			putchar((m % 10) + '0');
			if (n == 8 && m == 9)
				continue;
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
