#include "monty.h"


void cmd_push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
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
	printf("New number added; %d\n", push_data);
}

void cmd_pall( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, i am pall\n");
}

void cmd_pint( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am pint\n");
}

void cmd_pop( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am pop\n");
}

void cmd_swap( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, i am swap\n");
}
