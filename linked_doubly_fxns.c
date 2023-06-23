#include "monty.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: Pointer to the start of list
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current);
	}
}
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: Head to the list
 * @n: Value of the node to be added
 *
 * Return: The address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *current;

	if (head == NULL)
		return (NULL);
	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		my_dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	current->n = n;
	if (*head == NULL)
	{
		current->next = *head;
		current->prev = NULL;
		*head = current;
		return (*head);
	}
	(*head)->prev = current;
	current->next = (*head);
	current->prev = NULL;
	*head = current;
	return (*head);
}
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: Pointer to the list
 * @n: Value of the new node to be added
 *
 * Return: The address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *last;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		my_dprintf(2, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		new->prev = last;
		last->next = new;
	}
	return (new);
}
