#include "monty.h"


void cmd_push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
                exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->n = push_data;
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->n = push_data;
		new_node->prev = NULL;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}

}

void cmd_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	
}

void cmd_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

void cmd_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
	}
	temp = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
	}
	else
	{
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
	}
	free(temp);
}

void cmd_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		(*stack)->prev = NULL;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		temp->prev = *stack;
	}
}
