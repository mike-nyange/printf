#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/**
 * struct print - struct for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
#endif
