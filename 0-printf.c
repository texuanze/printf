#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - prints output in desired format
 * @format: output of the conversion specifier
 * Return: output length
 */
int _printf(const char *format, ...)
{
	int j = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ++format)
		{
			switch (*format++)
			{case 'c':
				_putchar(va_arg(args, int));
				j++;
				break;
				case 's':
				{char *s = va_arg(args, char *);
					while (*s)
					{_putchar(*s);
						j++;
						s++;
					}
					break;
					case '%':
					_putchar('%');
					j++;
					break;
					default:
					_putchar('%');
					_putchar(*(format - 1));
					j += 2;
					break;
				}
			}
		} else
		{_putchar(*format);
			j++;
			format++;
		}
	}
	va_end(args);
	return (j);
}
