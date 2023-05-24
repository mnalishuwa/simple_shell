#include "main.h"

/**
 * print_number - prints a number to stdout
 * Description: receives and int n, and prints it to stdout using _putchar
 *
 * @n: interger to be printed to stdout
 *
 * Return: void
 */

void print_number(int n)
{
	int temp, _digits, _remainder, result;

	temp = n;
	if (n == 0)
		_putchar(ASCII_ZERO);
	if (n < 0)
		_putchar(NEGATIVE_SIGN);
	/* get the number of digits in the number */
	for (_digits = 0; (n < 0) ? (temp < 0) : (temp > 0); _digits++)
		temp = temp / 10;
	/* loop per digit */
	for (_digits--; _digits >= 0; _digits--)
	{
		result = _pow_recursion(10, _digits);
		_remainder = (n % result);
		n = n / _pow_recursion(10, _digits);

		if (n < 0)
			n = -1 * n;
		_putchar(n + ASCII_ZERO);
		n = _remainder;
	}
}


/**
 * _pow_recursion - return x ^ y
 * Description: receives ints x, y and compute x^y
 *
 * @x: int arg 1
 * @y: int arg 2
 *
 * Return: int, x^y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}
