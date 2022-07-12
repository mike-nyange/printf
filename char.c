#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * print_s - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_s(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}
/**
  *print_Str - prints the string.
  *@args: list of arguments.
  *@len: number of chars.
  *
  *Return: length of characters printed.
  */
int print_S(va_list args, int len)
{
	int i;

	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{

		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			if (str[i] < 15)
			{
				len += _printf("\\x0");
				len += _printf("%X", str[i]);
				i++;
			}
			else
			{
				len += _printf("\\x");
				len += _printf("%X", str[i]);
				i++;
			}
		}
		else
		{
			len += _putchar(str[i]);
			i++;
		}
	}
	return (len);
}

/**
 * print_r - prints a string in reverse
 * @r: string to print
 *
 * Return: number of characters printed
 */
int print_r(va_list r)
{
	char *str;
	int i, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 * handle_percent - writes characters after a % if they
 * don't match anything in the struct
 * @ch1: the first char passed (always %)
 * @ch2: the char after the %
 * Return: 1 if ch2 is a % and 2 is ch2 is anything else
 */

int handle_percent(char ch1, char ch2)
{
	if (ch2 == '%')
	{
		write(1, &ch2, 1);
		return (1);
	}
	else
	{
		write(1, &ch1, 1);
		write(1, &ch2, 1);
		return (2);
	}
}
