#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        FILE *stream;
        unsigned int line_num = 0;
        char *buf = NULL, *token;
        size_t buf_size = 0;
        ssize_t nread;
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
        while ((nread = fgets(&buf, &buf_size, stream)) != -1)
        {
                line_num++;
                token = strtok(buf, " \t\n");
                if ((f = function_call(token)) != NULL)
                        f(NULL, line_num);
                else
                {
                        printf("L<%d>: unknown instruction <%s>\n", line_num, token);
			 free(buf);
                        exit(EXIT_FAILURE);
                }
                free(buf);
        }
        return (0);
}                                                                           
