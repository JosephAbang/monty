#include "monty.h"


void cmd_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *second_top;
	stack_t *top;
	int results;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second_top = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		results = second_top->n % top->n;
		second_top->n = results;
		cmd_pop(stack, line_number);
	}
}

void cmd_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next)
	{
		if ((temp->n > 65 && temp->n < 91) || (temp->n > 97 && temp->n < 123))
		{
			printf("%c", temp->n);
		}
		if (temp->next->next == NULL || temp->n == 0)
		{
			printf("\n");
			break;
		}
		temp = temp->next;
	}
}

void cmd_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}
