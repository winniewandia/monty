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
        dprintf(2, "L%u: ", n);
        dprintf(2, "usage: push integer\n");
        _free();
        exit(EXIT_FAILURE);
    }
    for (i = 0; globals.filename[i]; i++)
    {
        if (!isdigit(globals.filename[i]) && globals.filename[i] != '-')
        {
            dprintf(2, "L%u: ", n);
            dprintf(2, "usage: push integer\n");
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
    (void)n;
    stack_t *cp;

    cp = *head;

    while (cp != NULL)
    {
        printf("%d\n", cp->n);
        cp = cp->next;
    }
}
