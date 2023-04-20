#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - A function that prints anything.
 *
 * @format: A list of types of arguments passed to the function.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (if the string is NULL, print (nil) instead)
 *          Any other char should be ignored.
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *separator = "";
	char *current_arg;

	const char options[] = "cifs";

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (options[j])
		{
			if (format[i] == options[j])
			{
				printf("%s", separator);
				switch (format[i])
				{
					case 'c':
						printf("%c", va_arg(args, int));
						break;
					case 'i':
						printf("%d", va_arg(args, int));
						break;
					case 'f':
						printf("%f", va_arg(args, double));
						break;
					case 's':
						current_arg = va_arg(args, char *);
						printf("%s", current_arg ? current_arg : "(nil)");
						break;
					default:
						break;
				}
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");

	va_end(args);
}
