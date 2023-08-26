#include "monty.h"

/**
  * swap - swaps the top two elements of the stack.
  * @line_number: the current line being processed in the opcode file.
  * Return: 0 if swapping is successful and -1 if the stack has less than two
  * elements.
  */
int swap(unsigned int line_number)
{
	int ln, temp;

	ln = line_number;
	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
				ln);
		return (-1);
	}
	temp = top->n;
	top->n = (top->next)->n;
	(top->next)->n = temp;
	return (0);
}
/**
  * add - adds the top two elements of the stack.
  * @line_number: the line being processed in the opcode file.
  * Return: -1 if the stack has less than two elements and 0 if it is
  * successful.
  */
int add(unsigned int line_number)
{
	int ln, sum;

	ln = line_number;
	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", ln);
		return (-1);
	}
	sum = top->n + (top->next)->n;
	pop(line_number);
	top->n = sum;
	return (0);
}
