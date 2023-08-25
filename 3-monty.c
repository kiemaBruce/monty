#include "monty.h"
/**
  * printall - prints all elements of the stack.
  * Description: if the stack is empty it prints stack underflow.
  */
void printall(void)
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
