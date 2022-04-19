#include "main.h"
/**
 * _printf - produces output according to format
 * @format: character string
 * Return: nmber of characters printed
 */
int _printf(const char *format, ...)
{
	int (*func)(va_list, flags_t *);
	const char *p;
	va_list ap;
	flags_t flags = {0, 0, 0};

	register int cnt = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				cnt += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			func = get_print(*p);
			cnt += (func)
				? func(ap, &flags)
				: _printf("%%%c", *p);
		} else
			cnt += _putchar(*p);
	}
	_putchar(-1);
	va_end(ap);
	return (cnt);
}
