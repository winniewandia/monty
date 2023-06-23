#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 256
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var - global values to be used
 * @stack: Stack or queue
 * @current_line: The current line
 * @argument: argument containing the bytecode
 * @temp: Doubly linked list
 * @file: File descriptor
 * @line: input text
 */
typedef struct global_var
{
	int stack;
	unsigned int current_line;
	char *argument;
	stack_t *temp;
	FILE *file;
	char *line;
} gl_t;

extern gl_t globals;

void free_dlistint(stack_t *head);
void _free(void);
void start(FILE *file);
void parseBytecode(int argc, char *argv[]);
void (*opcodes(char *ops))(stack_t **stack, unsigned int line_number);
void _push(stack_t **head, unsigned int n);
void _pall(stack_t **head, unsigned int n);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void my_dprintf(int __attribute__((unused)) fd, const char *format, ...);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
