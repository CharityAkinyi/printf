#include "main.h"

/**
 * printfom-establish format specifiers
 * @format:string input length
 * @va_list args:string arguments
 *
 * Return:no return
 */
void printfom(const char *formt, va_list args)
{
	int formlen = 0;

	while (*formt)
	{
	if (*formlen == 0)
	{
	if (*formt == '%')
	formlen = 1;
	else
	{
	putchar(*formt);
	}
	else if (formlen == 1)
	{
	switch (*formt)
	{
	case 'c':
	{
	putchar(va_arg(args, int));
	break;
	}
	case 's':
	{
	const char *s = va_arg(args, const char *);
	while (*s)
	{
	putchar(*s++);
	}
	break;
	}
	case '%':
	{
	putchar('%');
	break;
	}
	formlen = 0;
	}
	}
	formt++;
	}
	}
}

	/**
	 * _printf-produces output according to a format
	 * @format:a character string
	 *
	 * Return:number of characters printed.
	 */
	int _printf(const char *format, ...)
	{
		va_list args;
		va_start(args, format);
		_printf(format, args);
		va_ends(args);
	}
