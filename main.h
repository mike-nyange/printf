#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/**
 * struct operation - a structure containing a char to compare with format specifiers.
 * and then choose the right function when it matches
 * @op: the char we want to compare to
 * @func: the address of the function we want to return if a char matches
 */
typedef struct operation
{
	char op;
	int (*func)(va_list);
} print_formats;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_d(va_list d);
int print_i(va_list i);
int print_b(va_list b);
int print_u(va_list u);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);
int handle_percent(char ch1, char ch2);
#endif
