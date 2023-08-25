#include "shell.h"
/**
 * token_save - a function to return an arry of pointers.
 * Return: tokens.
 */

char **token_save()
{
	char *cmd = NULL, *cmd_copy = NULL, *delim = " \n", *token = NULL;
	int value, i,  num_tokens;
	char **tokens = NULL;
	size_t n = 0;

	value = getline(&cmd, &n, stdin);
		if (value == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			num_tokens = 0;
			cmd_copy = strdup(cmd);
			token = strtok(cmd_copy, delim);

			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, delim);
			}
			tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
			if (tokens == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			i = 0;
			token = strtok(cmd, delim);
			while (token != NULL)
			{
				tokens[i] = strdup(token);
				i++;
				token = strtok(NULL, delim);
			}
			tokens[i] = NULL;
			free(cmd_copy);
		}
		return (tokens);
}
