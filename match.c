#include "main.h"

/**
 * match_type - matches format specifier to the corresponding function
 *
 * @directive: format specifier
 *
 * Return: a function the prints the argument passed
 * related to the specifier
*/

int (*match_type(char directive))(va_list)
{
	match_t matches[] = {
		{'c', handle_c},
		{'s', handle_s},
		{'i', handle_d},
		{'d', handle_d},
		{'%', handle_mod_sign},
		{' ', NULL}
	};
	int i;

	i = 0;
	while (i < 10)
	{
		if (directive == 0)
			return (matches[4].related_function);
		if (directive == matches[i].directive)
			return (matches[i].related_function);
		i++;
	}
	return (matches[5].related_function);
}
