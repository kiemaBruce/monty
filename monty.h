#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct strings_s - a struct for strings.
  * @s1: the first string.
  * @s2: the second string.
  * Description: this struct is for ease of passing two strings to
  * a function or returning the same from a function.
  */
typedef struct strings_s
{
	char *s1;
	char *s2;
} strings_t;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>

extern stack_t *top;
/*instruction_t *push(stack_t **stack, unsigned int line_number);*/
int push(int n);
int printall(void);
int pop(unsigned int line_number);
int str_parser(char *s, strings_t *st);
void free_strings_s(strings_t *st);
strings_t *initialize_strings_s(void);
int check_string(char *s1, char *s2);
int str_parser2(char *s, unsigned int line_number);
int check_int(char *s);
int getlen(char *s);
void free_stack(void);
void print_error_and_exit(int n, char *err, ...);
int pint(unsigned int line_number);
int count_stack(void);
int swap(unsigned int line_number);
int add(unsigned int line_number);
int sub(unsigned int line_number);
int divd(unsigned int line_number);
int mul(unsigned int line_number);

#endif /* MONTY_H */
