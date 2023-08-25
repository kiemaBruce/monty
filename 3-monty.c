#include "monty.h"
/**
  * printall - prints all elements of the stack.
  * Description: if the stack is empty it prints stack underflow.
  */
void printall(void)
{
	stack_t *temp;

	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "Stack underflow\n");
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
