#include "main.h"

int is_stack_too_short(stack_t **stack, unsigned int line_number) 
{
    if (*stack == NULL || (*stack)->next == NULL) 
    {
        fprintf(stderr, "L%d: stack too short\n", line_number);
        return (1);
    }
    return (0);
}

void _swap(stack_t **stack, unsigned int line_number) 
{
    if (is_stack_too_short(stack, line_number)) 
    {
        exit(EXIT_FAILURE);
    }

    int tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}

void _add(stack_t **stack, unsigned int line_number) 
{
    if (is_stack_too_short(stack, line_number)) 
    {
        exit(EXIT_FAILURE);
    }

    int sum = (*stack)->n + (*stack)->next->n;
    _pop(stack, line_number);
    (*stack)->n = sum;
}

void _nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number) 
{
}


void _pchar(stack_t **stack, unsigned int line_number) 
{
    if (*stack == NULL) 
    {
        fprintf(stderr, "L%d: stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    int val = (*stack)->n;
    if (val < 0 || val > 127) 
    {
        fprintf(stderr, "L%d: value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar(val);
    putchar('\n');
}

int _isalpha(int c) 
{
    return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}
