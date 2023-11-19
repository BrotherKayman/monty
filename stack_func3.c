#include "monty.h"
/**
* _pstr - Prints the string starting from the top of the stack.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
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
* _rotl - Rotates the stack to the top.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
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
* _rotr - Rotates the stack to the bottom.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
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
