#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - Prints a char
 * @args: List of arguments
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an int
 * @args: List of arguments
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float
 * @args: List of arguments
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - Prints anything
 * @format: List of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char c;
	void (*print_func[])(va_list) = {print_char, print_int, print_float, print_string};

	va_start(args, format);
	while (format[i])
	{
		c = format[i];
		switch (c)
		{
		case 'c':
			print_func[0](args);
			break;
		case 'i':
			print_func[1](args);
			break;
		case 'f':
			print_func[2](args);
			break;
		case 's':
			print_func[3](args);
			break;
		default:
			i++;
			continue;
		}

		if (format[i + 1])
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(args);
}
