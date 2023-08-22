#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 **/

int main(int argc, char **argv)
{
	FILE *stream;
	char *buf = NULL, *buf_copy, *token;
	size_t buf_size = 0, line_num = 0;
	ssize_t nread;
	void (*f);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&buf, &buf_size, stream)) != -1)
	{
		line_num++;
		buf_copy = strdup(buf);
		token = strtok(buf_copy, " \t");
		while (token != NULL)
		{
			token = strtok(NULL, " \t");
		}
		if ((f = function_call(token[0])) != NULL)
			f(__attribute__((unused)) stack,  __attribute__((unused)) line_num);
		else
		{
			printf("L<%d>: unknown instruction <%s>\n", line_num, token[0]);
			free(buf);
			free(buf_copy);
			exit(EXIT_FAILURE);
		}
		free(buf);
		free(buf_copy);
	}
	return (0);
}
