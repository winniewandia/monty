#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top
 * element of the stack
 * @head: Pointer to the head
 * @n: The line number;
 */
void _div(stack_t **head, unsigned int n)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n /= (*head)->n;
	_pop(head, n);
}

/**
 * _mul - multiplies the second top element of the stack with
 * the top element of the stack
 * @head: Pointer to the head
 * @n: The line number;
 */
void _mul(stack_t **head, unsigned int n)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n *= (*head)->n;
	_pop(head, n);
}

/**
 * _mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: Pointer to the head
 * @n: The line number;
 */
void _mod(stack_t **head, unsigned int n)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n %= (*head)->n;
	_pop(head, n);
}