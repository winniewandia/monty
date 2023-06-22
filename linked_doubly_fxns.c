#include "monty.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: Pointer to the start of list
 */
void free_dlistint(stack_t *head)
{
    stack_t *current, *next;

    current = head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
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
    stack_t *temp, *current;

    temp = malloc(sizeof(stack_t));
    if (temp == NULL)
        return (NULL);
    temp->n = n;
    temp->prev = NULL;
    current = *head;
    if (current != NULL)
    {
        while (current->prev != NULL)
            current = current->prev;
    }
    temp->next = current;
    if (current != NULL)
        current->prev = temp;
    *head = temp;
    return (temp);
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
        return (NULL);
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
