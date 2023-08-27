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
/**
  * rotr - rotates the stack to the bottom.
  * Description: The last element of the stack becomes the top element of the
  * stack.
  * Return: always 0 (success).
  */
int rotr(void)
{
	stack_t *trav;

	if (count_stack() <= 1)
		return (0);
	trav = top;
	while (trav != NULL)
	{
		if (trav->next == NULL)
		{
			(trav->prev)->next = NULL;
			trav->next = top;
			trav->prev = NULL;
			top = trav;
			break;
		}
		trav = trav->next;
	}
	return (0);
}
