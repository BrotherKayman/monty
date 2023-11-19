#include "monty.h"
/**
* _swap - Swaps the top two elements of the stack.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
*/
void _swap(stack_t **stack, unsigned int line_number)
{
stack_t *runner;
int tmp;
runner = *stack;
if (runner == NULL || runner->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
tmp = runner->n;
runner->n = runner->next->n;
runner->next->n = tmp;
}
/**
* _add - Adds the top two elements of the stack.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
*/
void _add(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
int sum = 0, i = 0;
if (tmp == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
while (tmp)
{
tmp = tmp->next;
i++;
}
if (stack == NULL || (*stack)->next == NULL || i <= 1)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
sum = (*stack)->next->n + (*stack)->n;
_pop(stack, line_number);
(*stack)->n = sum;
}
/**
* _pchar - Prints the ASCII value of the top element of the stack.
*
* @stack: Pointer to the stack.
* @line_number: Line number where the opcode occurs.
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
int val;
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
val = (*stack)->n;
if (val > 127 || val < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
putchar(val);
putchar('\n');
}
/**
* _isalpha - Checks if an integer corresponds to an alphabet character.
*
* @c: Integer value to be checked.
* Return: 1 if c is an alphabet character, 0 otherwise.
*/
int _isalpha(int c)
{
return (((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) ? 1 : 0);
}
