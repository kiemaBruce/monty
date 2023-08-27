#include "monty.h"

/**
  * modu - computes the remainder of  division of second top by top element.
  * @line_number: the line being processed in the opcode file.
  * Return: 0 if successful and -1 if the stack contains less than two
  * elements.
  */
int modu(unsigned int line_number)
{
	int mod;

	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
				line_number);
		return (-1);
	}
	mod = (top->next)->n % top->n;
	pop(line_number);
	top->n = mod;
	return (0);
}
