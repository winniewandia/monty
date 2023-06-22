The Monty Language Interpreter
The Monty language is a simple stack-based programming language. It uses a file containing bytecode instructions to specify the program logic. Here are the key aspects of Monty language syntax, semantics, and available instructions:

Syntax:

Instructions are written one per line.
Comments start with the '#' symbol and extend until the end of the line.
Blank lines and leading/trailing whitespace are ignored.
Semantics:

Monty uses a stack to store and manipulate data. It operates on the principle of Last-In, First-Out (LIFO).
Monty also provides a heap (or memory) for storing variables.
Instructions:

Stack Manipulation:

push <value>: Pushes a value onto the stack.
pall: Prints all values on the stack.
pint: Prints the value at the top of the stack.
pop: Removes the top element from the stack.
swap: Swaps the top two elements of the stack.
add: Adds the top two elements of the stack and stores the result in the second element, removing the top element.
sub: Subtracts the top element of the stack from the second element and stores the result in the second element, removing the top element.
mul: Multiplies the top two elements of the stack and stores the result in the second element, removing the top element.
div: Divides the second element of the stack by the top element and stores the result in the second element, removing the top element.
mod: Computes the remainder of the division of the second element of the stack by the top element and stores the result in the second element, removing the top element.
Memory Manipulation:

push <value>: Pushes a value onto the stack.
pall: Prints all values on the stack.
pint: Prints the value at the top of the stack.
pop: Removes the top element from the stack.
swap: Swaps the top two elements of the stack.
add: Adds the top two elements of the stack and stores the result in the second element, removing the top element.
sub: Subtracts the top element of the stack from the second element and stores the result in the second element, removing the top element.
mul: Multiplies the top two elements of the stack and stores the result in the second element, removing the top element.
div: Divides the second element of the stack by the top element and stores the result in the second element, removing the top element.
mod: Computes the remainder of the division of the second element of the stack by the top element and stores the result in the second element, removing the top element.
Control Flow:

label <label>: Defines a label for jumping.
jmp <label>: Jumps unconditionally to a label.
jnz <label>: Jumps to a label if the value at the top of the stack is not zero.
jz <label>: Jumps to a label if the value at the top of the stack is zero.
