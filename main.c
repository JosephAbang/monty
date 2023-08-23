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
	int len;
        void (*f)(stack_t **stack, unsigned int line_number);
	

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
        while (fgets(buf, sizeof(buf), stream) != NULL)
        {
                line_num++;
		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n')
			buf[len - 1] = '\0';
		if (strlen(buf) == 0)
			continue;

                token = strtok(buf, " \t\n");
                if ((f = function_call(token)) != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				push_data = atoi(token);
			}
                        f(NULL, line_num);
		}
                else
                {
                        printf("L<%d>: unknown instruction <%s>\n", line_num, token);
                        exit(EXIT_FAILURE);
                }
        }
        return (0);
}                                                                           
