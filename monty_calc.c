#include "monty.h"
/**
* @brief Subtracts the top element of the stack from the second top element.
*
* @param stack Pointer to the top of the stack
* @param line_number Line number where the opcode occurs
*/
void _sub(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = *stack;
int sub = 0, i = 0;
if (tmp == NULL || tmp->next == NULL)
{
fprintf(stderr, "L%d: can't subtract, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
while (tmp)
{
tmp = tmp->next;
i++;
}
if (*stack == NULL || (*stack)->next == NULL || i <= 1)
{
fprintf(stderr, "L%d: can't subtract, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
sub = (*stack)->next->n - (*stack)->n;
_pop(stack, line_number);
(*stack)->n = sub;
}
/**
* @brief Multiplies the top element of the stack by the second top element.
*
* @param stack Pointer to the top of the stack
* @param line_number Line number where the opcode occurs
*/
void _mul(stack_t **stack, unsigned int line_number)
{
int aux;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't multiply, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
else
{
aux = (*stack)->n;
_pop(stack, line_number);
(*stack)->n *= aux;
}
}
/**
* @brief Divides the second top element of the stack by the top element.
*
* @param stack Pointer to the top of the stack
* @param line_number Line number where the opcode occurs
*/
void _div(stack_t **stack, unsigned int line_number)
{
int div = 0;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't divide, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
else if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
else
{
div = (*stack)->n;
_pop(stack, line_number);
(*stack)->n /= div;
}
}
/**
* @brief Computes the modulo of the second top element by the top element.
*
* @param stack Pointer to the top of the stack
* @param line_number Line number where the opcode occurs
*/
void _mod(stack_t **stack, unsigned int line_number)
{
int mod = 0;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
else if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
else
{
mod = (*stack)->n;
_pop(stack, line_number);
(*stack)->n %= mod;
}
}
