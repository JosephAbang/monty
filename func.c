#include "monty.h"


void cmd_push( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am push and my data is:%d\n", push_data);
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
