#include "monty.h"

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
	globals.argument = NULL;
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
	char *line;
	void (*f)(stack_t **stack, unsigned int line_number);
	ssize_t bytesRead = 0;
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
	while ((bytesRead = _getline(&globals.line, &lineLength, file)) != -1)
	{
		line = strtok(globals.line, " \t\n");
		if (line && line[0] != '#')
		{
			f = opcodes(line);
			if (f == NULL)
			{
				my_dprintf(2, "L%u: ", globals.current_line);
				my_dprintf(2, "unknown instruction %s\n", line);
				_free();
				exit(EXIT_FAILURE);
			}
			globals.argument = strtok(NULL, " \t\n");
			f(&globals.temp, globals.current_line);
			globals.current_line++;
		}
		else
		{
			globals.current_line++;
			continue;
		}
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
