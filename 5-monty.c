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
	if (top->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n",
				line_number);
		return (-1);
	}
	mod = (top->next)->n % top->n;
	pop(line_number);
	top->n = mod;
	return (0);
}
/**
  * check_comment - checks whether a string is a comment.
  * @s: the string to be checked.
  * Return: 0 if it is a comment and -1 if it isn't.
  */
int check_comment(char *s)
{
	if (s[0] == '#')
		return (0);
	return (-1);
}
/**
  * str_parser2_helper - an extension of str_parser2.
  * @s1: the opcode string that is to be checked in order to determine the
  * appropriate action.
  * @line_number: the line in the opcode file that is being processed.
  * Return: either 0 or 1 depending on the results of the checks performed on
  * s1.
  */
int str_parser2_helper(char *s1, unsigned int line_number)
{
	int r;

	if (check_comment(s1) == 0)
	{
		r = 0;
	}
	else if (check_string(s1, "mul") == 0)
	{
		r = mul(line_number);
	}
	else if (check_string(s1, "mod") == 0)
	{
		r = modu(line_number);
	}
	else if (check_string(s1, "div") == 0)
	{
		r = divd(line_number);
	}
	else
	{/* opcode isn't a recongnized function */
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
				line_number, s1);
		r = -1;
	}
	return (r);
}
