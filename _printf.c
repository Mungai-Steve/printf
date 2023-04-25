#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - writes a function that outputs as formated
 * @format: argument which specifies format string
 * Return: total number of characters printed(count)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
	{
		case 'c':
			count += putchar(va_arg(args, int));
			break;

		case 's':
		{
		const char *str = va_arg(args, const char *);

		while (*str)
		{
			count += putchar(*str++);
		}
			break;
		}

		case '%':
			count += putchar('%');
			break;

		default:
			count += putchar('%');
			count += putchar(*format);
			break;
	}
	}
	else
	{
		count += putchar(*format);
	}

	format++;
	}

	va_end(args);

	return (count);
}

