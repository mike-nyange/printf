#include <stdio.h>
#include <stdlib.h>
/**
 *rev_string -reverses a string
 *@s:string to reverse
 *Return:pointer to reversed string
 */
char *rev_string(char *s)
{
	int i, max, half;
	char first, last;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	max = i - 1;
	half = max / 2;

	while (half >= 0)
	{
		first = s[max - half];
		last = s[half];
		s[half] = first;
		s[max - half] = last;
		half--;
	}
	return (s);
}
/**
 *base_len - finds length of number
 *@base: to be calculated
 *@num: checked
 *Return:length of base
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}
/**
 *hex_conv - converts a number to any base specified by user
 *@num:number to convert
 *Return:pointer to converted string
 */
char *hex_conv(int num)
{
	char *str;
	int i, len;

	i = 0;
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (num == 0)
	{
		str[i] = 0;
	}
	i = 0;
	while (num > 0)
	{
		if ((num % 16) < 10)
		{
			str[i] = (num % 16) + 48;
			i++;
		}
		else
		{
			str[i] = (num % 16) + 55;
			i++;
		}
		num /= 16;
	}
	rev_string(str);
	return (str);
}
/**
 *convert_to - convert numbers
 *@representation: char representation[] = "0123456789ABCDEF";
 *@num: num to tranasform
 *@base: base to transform num
 *Return: number into char pointer
 */
char *convert_to(char representation[], unsigned int num, int base)
{
	char *ptr;
	static char buffer[128];
	int mod = 0;

	ptr = &buffer[127];
	*ptr = '\0';

	do {
		mod = num % base;
		*--ptr = representation[mod];
		num /= base;
	} while (num != 0);
	return (ptr);
}
