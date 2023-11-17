#include "monty.h"

/**
 * @brief Prints the string starting from the top of the stack.
 *
 * @param stack Pointer to the stack.
 * @param line_number Line number where the opcode occurs.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;

	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || !_isalpha(c))
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * @brief Rotates the stack to the top.
 *
 * @param stack Pointer to the stack.
 * @param line_number Line number where the opcode occurs.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * @brief Rotates the stack to the bottom.
 *
 * @param stack Pointer to the stack.
 * @param line_number Line number where the opcode occurs.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
