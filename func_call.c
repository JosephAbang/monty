#include "monty.h"

/**
 * function_call: function that dynamically calls another
 * @cmd: Command
 * Return: ponter to a function
 */

void (*function_call(char *cmd))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd_arr[] =
	{
		{"push", cmd_push},
		{"pall", cmd_pall},
		{"pint", cmd_pint},
		{"pop", cmd_pop},
		{"swap", cmd_swap},
		{"add", cmd_add},
		{"nop", cmd_nop},
		{"sub", cmd_sub},
		{NULL, NULL}
	};
	int idx = 0;

	while (cmd_arr[idx].opcode)
	{
		if (strcmp(cmd_arr[idx].opcode,cmd) == 0)
		{
			return (cmd_arr[idx].f);
		}
		idx++;
	}
	return (NULL);
}
