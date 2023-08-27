#include "monty.h"

/**
  * rotl - rotates the stack to the top.
  * Description: The top element of the stack becomes the last one, and
  * the second top element of the stack becomes the first one.
  * Return: always 0 (success).
  */
int rotl(void)
{
	stack_t *trav, *new_top;

	if (count_stack() <= 1)
		return (0);
	new_top = top->next;
	trav = top;
	while (trav != NULL)
	{
		if (trav->next == NULL)
		{
			trav->next = top;
			top->prev = trav;
			top->next = NULL;
			top = new_top;
			top->prev = NULL;
			break;
		}
		trav = trav->next;
	}
	return (0);
}
