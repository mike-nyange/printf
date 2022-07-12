#include "main.h"
#include <stdlib.h>
/**
 * print_b - takes an unsigned int and prints it in binary notation
 * @list: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list list)
{
	unsigned int num;
	int i, j, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 2);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (-1);
	i = 0;
	while (num > 0)
	{
		str[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j] + '0');
	}
	free(str);
	return (len);
}

/**
 *print_p - prints an address
 *@list:list to increment
 *Return:count of characters
 */
int print_p(va_list list)
{
	char *hex, char *s = "(nil)";
	unsigned long int add = (unsigned long int)va_arg(list, void *);
	int c = 0, i, temp, len;

	if (add == 0)
	{
		for (i = 0; s[i]; i++)
		{
			_putchar(s[i]);
			c++; }
		return (c); }
	_putchar('0');
	_putchar('x');
	c = 2, i = 0;
	len = base_len(add, 16);
	hex = malloc((sizeof(char) * len) + 1);
	if (!hex)
		for (i = 0; s[i]; i++)
			_putchar(s[i]);
		return (5);
	while (add > 0)
	{
		temp = add % 16;
		if (temp > 9)
		{
			hex[i] = temp + 87;
			i++; }
		else
		{
			hex[i] = temp + 48;
			i++; }
		add /= 16;
	}
	rev_string(hex);
	for (i = 0; hex[i]; i++)
	{
		_putchar(hex[i]);
		c++;
	}
	return (c);
}
