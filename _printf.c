#include "main.h"

/**
 * _printf-produces output according to a format.
 * @format:a character string.
 *
 * Return:the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list fomatp;
	int i = 0;
	int chnum = 0;

	va_start(fomatp, format);
	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '\0')
	{
	break;
	}
	else if (format[i] == '%' && format[i + 1])
	{
	chnum += (*format_conversion(format[i + 1]))(valist);
	}
	else
	{
	chnum += _putchar(format[i]);
	}
	}
	va_end(fomatp);
	return (chnum);
}
