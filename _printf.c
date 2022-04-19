#include "main.h"
/**
 * _printf - produces output according to format
 * @format: character string
 * Return: nmber of characters printed
 */
int _printf(const char *format, ...)
{

	int i;
	int len = 0;
	char *newstr = NULL;

	while (format[len] != '\0')
	{
		len++;
	}

	newstr = malloc(sizeof(char) * (len + 1));

	if (newstr == NULL)
	{
		return (1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		newstr[i] = format[i];
	}
	newstr[i] = '\0';

	write(1, format, len);
	free(newstr);
	return (0);
}
