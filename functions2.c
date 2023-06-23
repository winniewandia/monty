#include "monty.h"

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
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * _swap - swaps the top two elements of the stack
 * @head: Pointer to the head
 * @n: The line number
 */
void _swap(stack_t **head, unsigned int n)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}

/**
 * _add - adds the top two elements of the stack
 * @head: Pointer to the head
 * @n: line number;
 */
void _add(stack_t **head, unsigned int n)
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
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n += (*head)->n;
	_pop(head, n);
}

/**
 * _nop - doesn't do anything
 * @head: Pointer to the head
 * @n: line number;
 */
void _nop(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
}