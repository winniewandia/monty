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
 * @head: The stack to be displayed
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
 * @format: The format specifiers
 */
void my_dprintf(int __attribute__((unused)) fd, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
