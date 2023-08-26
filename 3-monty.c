#include "monty.h"
/**
  * printall - prints all elements of the stack.
  * Description: if the stack is empty the function does nothing and just
  * returns 0.
  * Return: 0 on success (always).
  */
int printall(void)
{
	stack_t *temp;

	if (top != NULL)
	{
		temp = top;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
	return (0);
}
/**
  * free_stack - frees a stack_t stack.
  */
void free_stack(void)
{
	stack_t *temp, *temp2;

	if (top != NULL)
	{
		temp = top;
		while (temp != NULL)
		{
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
		/*free(top);*/
	}
}
/**
  * print_error_and_exit - prints an error message to  STDERR_FILENO end exits.
  * @n: the number of string arguments to the function.
  * @err: the first string argument. It is used to form the error message.
  */
void print_error_and_exit(int n, char *err, ...)
{
	va_list args;

	va_start(args, err);
	if (n == 1)
	{
		dprintf(STDERR_FILENO, "%s\n", (const char *)err);
	}
	else if (n == 2)
	{
		dprintf(STDERR_FILENO, "%s%s\n", (const char *)err,
				va_arg(args, char *));
	}
	va_end(args);
	exit(EXIT_FAILURE);
}
/**
  * pint - prints the value at the top of the stack plus a new line.
  * @line_number: the current line being processed in the opcode file.
  * Return: 0 if it executes successfully and -1 if the stack is empty.
  */
int pint(unsigned int line_number)
{
	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
				line_number);
		return (-1);
	}
	printf("%d\n", top->n);
	return (0);
}
/**
  * count_stack - counts the number of elements on the stack.
  * Return: the number of elements in the stack.
  */
int count_stack(void)
{
	stack_t *temp;
	int n;

	if (top == NULL)
		return (0);
	temp = top;
	n = 0;
	while (1)
	{
		if (temp == NULL)
			break;
		n++;
		temp = temp->next;
	}
	return (n);
}
