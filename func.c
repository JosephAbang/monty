#include "monty.h"
#include <stdio.h>
void cmd_push( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am push");
}

void cmd_pall( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, i am Pall");
}

void cmd_pint( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am pint");
}

void cmd_pop( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, I am pop");
}

void cmd_swap( __attribute__((unused)) stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	printf("Hey, i am swap");
}
