#include "monty.h"


void cmd_mod(stack_t **stack, unsigned int line_number)
{
        stack_t *second_top;
        stack_t *top;
        int results;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L<%d>: can't mod, stack too short\n", line_number);
                free_stack(stack);
		exit(EXIT_FAILURE);
        }
        top = *stack;
        second_top = top->next;
        if (top->n == 0)
        {
                fprintf(stderr, "L<%d>: division by zero", line_number);
                free_stack(stack);
		exit(EXIT_FAILURE);
        }
        else
        {
                results = second_top->n % top->n;
                second_top->n = results;
                cmd_pop(stack, line_number);
        }
}
