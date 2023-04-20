#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - A function that prints anything.
 *
 * @format: A list of types of arguments passed to the function.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (if the string is NULL, print (nil) instead
 *          Any other char should be ignored
 *
 * Return: Nothing.
 */

void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *separator = "";

	const char options[] = "cifs";
	char *current_arg;

	/* initialize the arguments */
	va_start(args, format);

	/* loop through the format string */
	while (format && format[i])
	{
		/* loop through the options */
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
						if (current_arg == NULL)
							current_arg = "(nil)";
						printf("%s", current_arg);
						break;
				}
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	
	/* clean up the arguments */
	va_end(args);

	/* print a new line */
	printf("\n");
}
