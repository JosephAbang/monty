#include "monty.h"

void cmd_add(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	stack_t *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		second_top = top->next;
		results = second_top->n + top->n;
		second_top->n = results;
		cmd_pop(stack, line_number);
	}
}

void cmd_nop(stack_t **stack, unsigned int line_number)
{
	        (void)stack;
		(void)line_number;
}

void cmd_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	stack_t *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L<%d>: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		second_top = top->next;
		results = second_top->n - top->n;
		second_top->n = results;
		cmd_pop(stack, line_number);
	}
}

void cmd_div(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	stack_t *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second_top = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		results = second_top->n / top->n;
		second_top->n = results;
		cmd_pop(stack, line_number);
	}
}

void cmd_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top, *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = *stack;
		second_top = top->next;
		results = second_top->n * top->n;
		second_top->n = results;
		cmd_pop(stack, line_number);
	}
}
