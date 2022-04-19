#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/*_printf*/
int _printf(const char *format, ...);

/*print number*/
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int cnt_digit(int i);

/*get_print*/
int (*get_print(char s))(va_list, flags_t *);

/*get_flags*/
int get_flag(char s, flags_t *f);



/*write_funcs*/
int _putchar(char c);
int _puts(char *str);



#endif
