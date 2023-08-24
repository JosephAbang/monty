#include "monty.h"

void cmd_add(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	stack_t *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("<L%d>: can't add, stack too short\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;;
		second_top = top->next;
		results = second_top->n + top->n;
		second_top->n = results;
		*stack = second_top;
		free(top);
	}
}

void cmd_nop(stack_t **stack, unsigned int line_number)
{
	        (void)stack;
		(void)line_number;
}
