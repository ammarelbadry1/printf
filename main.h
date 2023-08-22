#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct match - Struct match
 *
 * @directive: The directive
 * @related_function: The function associated
 */
typedef struct match
{
	char directive;
	int (*related_function)(va_list);
} match_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*match_type(char directive))(va_list);
int handle_c(va_list);
int handle_s(va_list);
int handle_i(va_list);
int handle_d(va_list);
int handle_mod_sign(va_list);


#endif
