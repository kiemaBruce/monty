#include "monty.h"

/**
  * swap - swaps the top two elements of the stack.
  * @line_number: the current line being processed in the opcode file.
  * Return: 0 if swapping is successful and -1 if the stack has less than two
  * elements.
  */
int swap(unsigned int line_number)
{
	int temp;

	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
				line_number);
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
	int sum;

	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		return (-1);
	}
	sum = top->n + (top->next)->n;
	pop(line_number);
	top->n = sum;
	return (0);
}
/**
  * sub - subtracts the top from the second top element of stack.
  * @line_number: the line being processed in the opcode file.
  * Return: 0 if it is successful and -1 if the stack has less than two
  * elements.
  */
int sub(unsigned int line_number)
{
	int diff;

	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				line_number);
		return (-1);
	}
	diff = (top->next)->n - top->n;
	pop(line_number);
	top->n = diff;
	return (0);
}
/**
  * divd - divides the second top element by the top element of the stack.
  * @line_number: the line being processed in the opcode file.
  * Return: 0 if successful and -1 if either the stack has less than two
  * elements or if the top element of the stack is zero.
  */
int divd(unsigned int line_number)
{
	int quotient;

	if (count_stack() < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short",
				line_number);
		return (-1);
	}
	if (top->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero",
				line_number);
		return (-1);
	}
	quotient = (top->next)->n / top->n;
	pop(line_number);
	top->n = quotient;
	return (0);
}
