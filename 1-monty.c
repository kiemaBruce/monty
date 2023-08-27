#include "monty.h"

void blank_declaration(void);
stack_t *top;

/**
  * main - executes opcodes.
  * @argc: the number of command line arguments including the program name.
  * @argv: an array of strings. The strings are the command line arguments that
  * are provided to the program.
  * Return: it will exit with exit code EXIT_SUCCESS on success and
  * EXIT_FAILURE on failure.
  */
int main(int argc, char **argv)
{
	int e, p;
	FILE *monty_f;
	char *str;
	size_t n;
	strings_t *st;
	unsigned int line_number;

	if (argc != 2)
		print_error_and_exit(1, "USAGE: monty file");
	monty_f = fopen(argv[1], "r");
	if (monty_f == NULL)
		print_error_and_exit(2, "Error: Can't open file ", argv[1]);
	line_number = 0;
	while (1)
	{
		str = NULL;
		errno = n = 0;
		if (getline(&str, &n, monty_f) == -1)
		{
			if (errno != 0)
			{
				perror("Getline");
				e = EXIT_FAILURE;
			} else
			{ /* EOF */
				e = EXIT_SUCCESS;
			}
			free(str);
			free_stack();
			fclose(monty_f);
			exit(EXIT_FAILURE);
		}
		line_number++;
		st = initialize_strings_s();
		if (st == NULL)
		{
			e = EXIT_FAILURE;
			break;
		}
		p = str_parser(str, st);
		if (p == -1)
		{
			e = EXIT_FAILURE;
			break;
		}
		if (p == 1)
		{
			free(str);
			free_strings_s(st);
			continue;
		}
		if (str_parser2(st->s2, line_number) == -1)
		{
			e = EXIT_FAILURE;
			free_strings_s(st);
			fclose(monty_f);
			free_stack();
			exit(EXIT_FAILURE);
			/*break;*/
		}
		free_strings_s(st);
	}
	free_strings_s(st);
	fclose(monty_f);
	free_stack();
	exit(e);
	return (0);
}
/**
  * getlen- returns the length of a string.
  * @s: the string whose length is to be determined.
  * Description: the terminating NUL byte isn't counted.
  * Return: the length.
  */
int getlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/**
  * free_strings_s - frees a strings_t object.
  * @st: pointer to the object to be freed.
  */
void free_strings_s(strings_t *st)
{
	free(st->s1);
	free(st->s2);
	free(st);
}
/**
  * initialize_strings_s - initializes a strings_t objects to NULL.
  * Return: pointer to the struct object if successful, or NULL if it fails.
  */
strings_t *initialize_strings_s(void)
{
	strings_t *st;

	st = malloc(sizeof(strings_t));
	if (st == NULL)
	{
		dprintf(STDERR_FILENO, "Stack overflow\n");
		return (NULL);
	}
	st->s1 = NULL;
	st->s2 = NULL;
	return (st);
}
/**
  * str_parser - parses a string received from getline.
  * @s: the string to be parsed.
  * @st: the string struct object that is to be used to store the strings.
  * Description: the terminating newline, and preceeding spaces and tabs are
  * removed.
  * Return: 0 if successful. It returns 1 if the string is composed entirely of
  * spaces and/ or tabs or if the string is just a newline character. If it
  * encounters an error it returns -1.
  */
int str_parser(char *s, strings_t *st)
{
	int i;

	if (s == NULL)
		return (-1);
	if (getlen(s) == 1 && s[0] == '\n')
		return (1);
	i = 0;
	while (s[i] != '\0') /* Remove terminating newline */
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
	for (i = 0; i < getlen(s); i++) /* Replace tabs with spaces */
	{
		if (s[i] == '\t')
			s[i] = ' ';
	}
	st->s1 = s;
	for (i = 0; i < getlen(s); i++) /* Remove preceeding tabs and spaces */
	{
		if (s[0] == '\t' || s[0] == ' ')
		{
			while (i < getlen(s))
			{
				if (s[i] != '\t' && s[i] != ' ')
				{
					st->s2 = strdup(s + i);
					if (st->s2 == NULL)
					{
						dprintf(STDERR_FILENO, "Stack overflow\n");
						return (-1);
					}
					return (0);
				}
				if (i == (getlen(s) - 1))/*Tabs & spaces only*/
				{
					st->s1 = NULL;
					st->s2 = NULL;
					return (1);
				}
				i++;
			}
		} else
		{
			st->s2 = strdup(st->s1);
			return (0);
		}
	}
	return (0);
}
