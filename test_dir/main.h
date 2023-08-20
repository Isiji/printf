#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

/**
 * struct format - struct op
 * @frt: the format string
 * @fxn: associated function
*/
struct format
{
	char fmt;
	int (*fx)(va_list, char [])
}
/**
 * typedef struct format fmt_t - struct op
 * @format: is the format.
 * @fmt_t: pointer to the associated function.
 */
typedef struct fomrmat frm_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif
