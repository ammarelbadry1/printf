#include "main.h"
/**
 * handle_c - handle c directive
 *
 * @arguments: the list that we will get
 * the corresponding argument from it.
 *
 * Return: the length of printed characters
*/
int handle_c(va_list arguments)
{
	_putchar(va_arg(arguments, int));
	return (1);
}

/**
 * handle_d - handle d directive
 *
 * @arguments: the list that we will get
 * the corresponding argument from it.
 *
 * Return: the length of printed characters
 */
int handle_d(va_list arguments)
{
	unsigned int m, d, digit_count, character_count = 0;
	int target;

	target = va_arg(arguments, int);
	if (target < 0)
	{
		_putchar(45);
		character_count++;
		m = target * -1;
	}
	else
	{
		m = target;
	}

	d = m;
	digit_count = 1;

	while (d > 9)
	{
		d /= 10;
		digit_count *= 10;
	}

	while (digit_count >= 1)
	{
		_putchar(((m / digit_count) % 10) + 48);
		character_count++;
		digit_count /= 10;
	}
	return (character_count);
}

/**
 * handle_i - handle i directive
 *
 * @arguments: the list that we will get
 * the corresponding argument from it.
 *
 * Return: the length of printed characters
 */
int handle_i(va_list arguments __attribute__ ((unused)))
{
	return (0);
}

/**
 * handle_s - handle s directive
 *
 * @arguments: the list that we will get
 * the corresponding argument from it.
 *
 * Return: the length of printed characters
 */
int handle_s(va_list arguments)
{
	char *str = va_arg(arguments, char *);
	int length = 0;

	if (str == NULL)
	{
		str = "(null)";
		while (str[length] != 0)
		{
			_putchar(str[length]);
			length++;
		}
		return (length);
	}
	else
	{
		while (*str != '\0')
		{
			_putchar(*str);
			str++;
			length++;
		}
	}

	return (length);
}

/**
 * handle_mod_sign - handle modulo sign
 *
 * @arguments: the list that we will get
 * the corresponding argument from it.
 *
 * Return: the length of printed characters
 */
int handle_mod_sign(va_list arguments __attribute__((unused)))
{
	_putchar('%');
	return (1);
}
