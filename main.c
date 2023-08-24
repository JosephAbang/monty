#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int push_data;

int main(int argc, char **argv)
{
        FILE *stream;
        unsigned int line_num = 0;
        char buf[256], *token;
	int len, is_int;
	stack_t **stack;
        void (*f)(stack_t **stack, unsigned int line_number);
	size_t i;
	

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        stream = fopen(argv[1], "r");
        if (stream == NULL)
        {
                fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
                exit(EXIT_FAILURE);
        }
	
	stack = malloc(sizeof(stack_t));
	*stack = NULL;
        while (fgets(buf, sizeof(buf), stream) != NULL)
        {
                line_num++;
		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n')
			buf[len - 1] = '\0';
		if (strlen(buf) == 0)
			continue;
                token = strtok(buf, " \t\n");
		if (token[0] == '#')
			continue;
                if ((f = function_call(token)) != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token == NULL || strlen(token) == 0)
				{
					fprintf(stderr, "L<%d>: usage: push integer\n", line_num);
					free_stack(stack);
					fclose(stream);
					exit(EXIT_FAILURE);
				}
				is_int = 1;
				for (i = 0; i < strlen(token); i++)
				{
					if (!isdigit(token[i]))
					{
						is_int = 0;
						break;
					}
				}
				if (!is_int)
				{
					fprintf(stderr, "L<%d>: usage: push integer\n", line_num);
					free_stack(stack);
					fclose(stream);
					exit(EXIT_FAILURE);
				}
				push_data = atoi(token);
			}
			if (stack == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free_stack(stack);
				fclose(stream);
				exit(EXIT_FAILURE);
			}

                        f(stack, line_num);	
		}
                else
                {
                        fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_num, token);
		       	free_stack(stack);
			fclose(stream);
			exit(EXIT_FAILURE);
                }
        }
	free_stack(stack);
	fclose(stream);
        return (0);
}

void free_stack(stack_t **stack)
{
	stack_t *temp, *next_temp;
	temp = *stack;

        while (temp)
        {
                next_temp = temp->next;
                free(temp);
                temp = next_temp;
        }
        free(stack);
}
