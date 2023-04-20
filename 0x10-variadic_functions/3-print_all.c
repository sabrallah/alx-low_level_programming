#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - prints a char
 * @ap: va_list with the char to print
 * @separator: separator to print before the char
 */
void print_char(va_list ap, char *separator)
{
	printf("%s%c", separator, va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: va_list with the int to print
 * @separator: separator to print before the int
 */
void print_int(va_list ap, char *separator)
{
	printf("%s%d", separator, va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: va_list with the float to print
 * @separator: separator to print before the float
 */
void print_float(va_list ap, char *separator)
{
	printf("%s%f", separator, va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: va_list with the string to print
 * @separator: separator to print before the string
 */
void print_string(va_list ap, char *separator)
{
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s%s", separator, str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *separator = "";
	void (*print_func[])(va_list, char *) = {print_char, print_int,
		print_float, print_string};
	char format_specifiers[] = {'c', 'i', 'f', 's'};
	int j;

	/* Initialize the argument list */
	va_start(ap, format);

	/* Process each character in the format string */
	while (format[i])
	{
		/* Reset the separator for the next iteration */
		if (i > 0)
			separator = ", ";

		/* Handle each format specifier */
		for (j = 0; j < 4; j++)
		{
			if (format[i] == format_specifiers[j])
			{
				print_func[j](ap, separator);
				break;
			}
		}

		if (j == 4)
			separator = "";

		i++;
	}

	/* Clean up */
	va_end(ap);

	/* Print a newline at the end */
	printf("\n");
}
