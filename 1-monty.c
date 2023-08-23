#include "monty.h"

stack_t *top;

int main(void)
{
	push();
	printall();
	pop();
	printall();
	pop();
	printall();
	pop();
	printall();
	return (0);
}
void push(void)
{
	int value, i;
	stack_t *new;
	
	for (i = 0; i < 3; i++)
	{
		printf("Enter value: ");
		scanf("%d", &value);

		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			dprintf(STDERR_FILENO, "Stack overflow\n");
			break;
		}
		if (top == NULL) /* Empty stack */
		{
			new->next = NULL;
			new->prev = NULL;
			new->n = value;
			top = new;
			continue;
		}
		else
		{
			new->next = top;
			new->prev = NULL;
			new->n = value;
			top->prev = new;
			top = new;
		}	
	}
}
void pop(void)
{
	stack_t *temp;

	if (top == NULL)
	{
		dprintf(STDERR_FILENO, "Stack underflow\n");
	} else
	{
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
	}	
}
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
