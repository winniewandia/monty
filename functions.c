#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @head: The linked list
 * @n: Line number
 */
void _push(stack_t **head, unsigned int n)
{
	int i, arg;

	if (!globals.filename)
	{
		my_dprintf(2, "L%u: ", n);
		my_dprintf(2, "usage: push integer\n");
		_free();
		exit(EXIT_FAILURE);
	}
	for (i = 0; globals.filename[i] != '\0'; i++)
	{
		if (!isdigit(globals.filename[i]) && globals.filename[i] != '-')
		{
			my_dprintf(2, "L%u: ", n);
			my_dprintf(2, "usage: push integer\n");
			_free();
			exit(EXIT_FAILURE);
		}
	}
	arg = atoi(globals.filename);

	if (globals.stack == 1)
		add_dnodeint(head, arg);
	else
		add_dnodeint_end(head, arg);
}

/**
 * _pall - displays all elements of stack
 * @stack: The stack to be displayed
 * @n: Line number
 */
void _pall(stack_t **head, unsigned int n)
{
	stack_t *cp;

	(void)n;

	cp = *head;

	while (cp != NULL)
	{
		printf("%d\n", cp->n);
		cp = cp->next;
	}
}
/**
 * my_dprintf - acts like my_dprintf
 * @fd: No of bytes
 * format: The format specifiers
 */
void my_dprintf(int __attribute__((unused)) fd, const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
/**
 * _getline - returns number of bytes read
 * @n: Size of line
 * @stream: Where the input is
 *
 * Return: Number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		(*lineptr)[pos++] = c;

		if (pos == *n)
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
			{
				return -1;
			}
			*lineptr = new_ptr;
		}
		if (c == '\n')
		{
			break;
		}
	}
	(*lineptr)[pos] = '\0';
	return (pos > 0) ? (ssize_t)pos : -1;
}
