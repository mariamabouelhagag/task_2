#include "shell.h"
/**
 * main - the main function.
 * @tokens: the array of pointers to be execluded.
 *
 * Return: 0.
 */

int main(void)
{
	pid_t pid;
	char **tokens = NULL;
	int i;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		tokens = token_save();
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}
		if (pid == 0)
		{
			if (execvp(tokens[0], tokens) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
		}
	}
	return (0);
}
