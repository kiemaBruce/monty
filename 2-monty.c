#include "monty.h"

/**
  * check_int - checks whether all chars in a string are integers.
  * @s: the string to be checked.
  * Return: 0 if all chars are integers, and -1 if at least one isn't an
  * integer.
  */
int check_int(char *s)
{
	int i;

	/* For negative numbers */
	if (s[0] == '-')
	{
		for (i = 1; i < getlen(s); i++)
		{
			if (s[i] < 48 || s[i] > 57)
				return (-1);
		}
	} else
	{
		for (i = 0; i < getlen(s); i++)
		{
			if (s[i] < 48 || s[i] > 57)
				return (-1);
		}
	}
	return (0);
}
/**
  * str_parser2 - executes the relevant function based on the opcode.
  * @s: the string that contains the opcode and its argument if any.
  * @line_number: the current line of the file that is being executed.
  * Return: 0 if it executes successfully, and -1 if there is an error.
  */
int str_parser2(char *s, unsigned int line_number)
{
	char *s1, *s2;
	int r;

	s1 = strtok(s, " ");
	if (check_string(s1, "push") == 0)
	{
		s2 = strtok(NULL, " ");
		if (s2 == NULL || check_int(s2) == -1)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			r = -1;
		} else
			r = push(atoi(s2));
	} else if (check_string(s1, "pall") == 0)
		r = printall();
	else if (check_string(s1, "pint") == 0)
		r = pint(line_number);
	else if (check_string(s1, "pop") == 0)
		r = pop(line_number);
	else if (check_string(s1, "swap") == 0)
		r = swap(line_number);
	else if (check_string(s1, "add") == 0)
		r = add(line_number);
	else if (check_string(s1, "nop") == 0)
		r = 0;
	else if (check_string(s1, "sub") == 0)
		r = sub(line_number);
	else
	{ /* Perform additional checks on s1 */
		r = str_parser2_helper(s1, line_number);
	}
	return (r);
}
/**
  * check_string - checks whether two strings are similar.
  * @s1: first string.
  * @s2: second string.
  * Return: 0 if the two strings are the same and -1 if they aren't. It also
  * returns -1 if either s1 or s2 or both are NULL.
  */
int check_string(char *s1, char *s2)
{
	int i;

	if (getlen(s1) != getlen(s2))
		return (-1);
	for (i = 0; i < getlen(s1); i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
/*instruction_t *push(stack_t **stack, unsigned int line_number)*/
/**
  * push - adds a new element on top of the stack.
  * @n: the new element to be added.
  * Return: 0 on success and -1 on failure.
  */
int push(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Stack overflow\n");
		return (-1);
	}
	if (top == NULL) /* Empty stack */
	{
		new->next = NULL;
		new->prev = NULL;
		new->n = n;
		top = new;
	}
	else
	{
		new->next = top;
		new->prev = NULL;
		new->n = n;
		top->prev = new;
		top = new;
	}
	return (0);
}
/**
  * pop - removes the top element of the stack.
  * @line_number: the current line in the opcode file being processed.
  * Return: 0 if it is successful in popping and -1 if the stack is empty.
  */
int pop(unsigned int line_number)
{
	stack_t *temp;

	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
				line_number);
		return (-1);
	}
	temp = top;
	if (top->next == NULL)
	{
		top = NULL;
	} else
	{
		(top->next)->prev = NULL;
		top = top->next;
	}
	free(temp);
	return (0);
}
