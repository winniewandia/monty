#include "monty.h"
#include <stdio.h>

gl_t globals;
/**
 * _free - frees the global variables
 */
void _free(void)
{
	free_dlistint(globals.temp);
	free(globals.line);
	fclose(globals.file);
}
/**
 * start - Initializes the globals
 * @file: The file descriptor
 */
void start(FILE *file)
{
	globals.stack = 1;
	globals.current_line = 1;
	globals.filename = NULL;
	globals.temp = NULL;
	globals.file = file;
	globals.line = NULL;
}
/**
 * opcodes - chooses the right instruction
 * @ops: Instruction to execute
 *
 * Return: Pointer to the function to be done
 */
void (*opcodes(char *ops))(stack_t **stack, unsigned int line_number)
{
	instruction_t code[] = {
	    {"push", _push},
	    {"pall", _pall},
	    {NULL, NULL}};
	int i;

	for (i = 0; code[i].opcode; i++)
	{
		if (strcmp(code[i].opcode, ops) == 0)
		{
			break;
		}
	}
	return (code[i].f);
}
/**
 * parseBytecode - reads and interprets Monty bytecode files
 * @argc: Number of arguments
 * @argv: Pointer to the array of arguments
 */
void parseBytecode(int argc, char *argv[])
{
	FILE *file;
	char *line[2] = {NULL, NULL};
	void (*f)(stack_t **stack, unsigned int line_number);
	ssize_t bytesRead;
	size_t lineLength = 256;

	if (argc == 1 || argc > 2)
	{
		my_dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		my_dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	start(file);
	bytesRead = getline(&globals.line, &lineLength, file);
	while (bytesRead != -1)
	{
		line[0] = strtok(globals.line, " \t\n");
		if (line[0][0] != '#' && line[0])
		{
			f = opcodes(line[0]);
			if (f == NULL)
			{
				my_dprintf(2, "L%u: ", globals.current_line);
				my_dprintf(2, "unknown instruction %s\n", line[0]);
				_free();
				exit(EXIT_FAILURE);
			}
			globals.filename = strtok(NULL, " \t\n");
			f(&globals.temp, globals.current_line);
		}
		bytesRead = getline(&globals.line, &lineLength, file);
		globals.current_line++;
	}
	_free();
}
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Pointer to array of arguments
 *
 * Return: Always 1 if success 0 otherwise
 */
int main(int argc, char *argv[])
{
	parseBytecode(argc, argv);
	return (0);
}
