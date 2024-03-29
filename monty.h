#ifndef _MONTY_H_
#define _MONTY_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>


extern FILE *stream;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 **/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*function_call(char *cmd))(stack_t **stack, unsigned int line_number);
void cmd_push(stack_t **stack, unsigned int line_number);
void cmd_pall(stack_t **stack, unsigned int line_number);
void cmd_pint(stack_t **stack, unsigned int line_number);
void cmd_pop(stack_t **stack, unsigned int line_number);
void cmd_swap(stack_t **stack, unsigned int line_number);
void cmd_add(stack_t **stack, unsigned int line_number);
void cmd_nop(stack_t **stack, unsigned int line_number);
void cmd_sub(stack_t **stack, unsigned int line_number);
void cmd_div(stack_t **stack, unsigned int line_number);
void  cmd_mul(stack_t **stack, unsigned int line_number);
void cmd_mod(stack_t **stack, unsigned int line_numberr);
void free_stack(stack_t **stack);
void cmd_pchar(stack_t **stack, unsigned int line_number);
void cmd_pstr(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
