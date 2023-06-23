#include <monty.h>

/**
 * _pop - removes the top element of the stack
 *
 * @head: Pointer to the start of the list
 * @n: The line number
 * Return: no return
 */
void _pop(stack_t **head, unsigned int n)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		my_dprintf(2, "L%u: can't pop an empty stack\n", n);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}