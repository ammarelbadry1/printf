#include "main.h"

/**
 * _printf - The driver function that prints formatted string
 *
 * @format: Formated string to be printed
 *
 * Return: The length of the string
 */

int _printf(const char *format, ...)
{
	int i, count_current, count_remote;
	int (*related_function)();
	va_list arguments;
	int is_37_before = 1;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	i = 0;
	count_current = 0;
	count_remote = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == 37 && format[i + 1] != 0)
		{
			related_function = match_type(format[i + 1]);
			if (related_function == NULL)
			{
				is_37_before = 0;
				_putchar(37);
				_putchar(format[i + 1]);
				count_remote += 2;
			}
			else
				count_remote += related_function(arguments);
			i += 2;
			continue;
		}
		else if (format[i] == 37 && format[i + 1] == 0 && is_37_before)
		{
			count_remote = -count_current - 1;
			break;
		}
		_putchar(format[i]);
		count_current++;
		i++;
	}
	va_end(arguments);
	return (count_current + count_remote);
}
