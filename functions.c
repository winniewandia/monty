#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @head: The linked list
 * @n: Line number
 */
void _push(stack_t **head, unsigned int n)
{
	int i, arg;

	if (!globals.argument)
	{
		my_dprintf(2, "L%u: ", n);
		my_dprintf(2, "usage: push integer\n");
		_free();
		exit(EXIT_FAILURE);
	}
	for (i = 0; globals.argument[i] != '\0'; i++)
	{
		if (!isdigit(globals.argument[i]) && globals.argument[i] != '-')
		{
			my_dprintf(2, "L%u: ", n);
			my_dprintf(2, "usage: push integer\n");
			_free();
			exit(EXIT_FAILURE);
		}
	}
	arg = atoi(globals.argument);

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
	ssize_t bytesRead;
	size_t bufferSize = 0;
	char *buffer = NULL, *newBuffer;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}
	if (*lineptr == NULL || *n == 0)
	{
		bufferSize = 128;
		*lineptr = (char *)malloc(bufferSize);
		if (*lineptr == NULL)
		{
			return -1;
		}
		*n = bufferSize;
	}
	bytesRead = 0;
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF || c == '\n')
		{
			break;
		}

		if (bytesRead >= *n - 1)
		{
			bufferSize *= 2;
			newBuffer = (char *)realloc(*lineptr, bufferSize);
			if (newBuffer == NULL)
			{
				return -1;
			}
			*lineptr = newBuffer;
			*n = bufferSize;
		}

		(*lineptr)[bytesRead] = (char)c;
		bytesRead++;
	}
	if (bytesRead == 0 && c == EOF)
	{
		return (-1);
	}

	(*lineptr)[bytesRead] = '\0';

	return (bytesRead);
}
/**
 * _realloc - reallocates memory
 * @ptr: Pointer to the orig size
 * @old_size: Old size of the block
 * @new_size: The new allocated size
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	void *new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		size_t min_size = (old_size < new_size) ? old_size : new_size;

		for (size_t i = 0; i < min_size; i++)
		{
			((char *)new_ptr)[i] = ((char *)ptr)[i];
		}

		free(ptr);
	}

	return (new_ptr);
}
