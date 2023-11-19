#include "monty.h"

/**
 * @brief Pushes an integer onto the stack.
 *
 * @param stack Pointer to the top of the stack.
 * @param line_number Number of line where opcode occurs.
 */
void _push(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *top;

    top = malloc(sizeof(stack_t));
    if (top == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    top->n = var_global.push_arg;
    top->next = *stack;
    top->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = top;
    *stack = top;
}

/**
 * @brief Prints all elements of the stack.
 *
 * @param stack Pointer to linked list stack.
 * @param line_number Number of line where opcode occurs.
 */
void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *runner = *stack;

    while (runner != NULL)
    {
        printf("%d\n", runner->n);
        runner = runner->next;
    }
}

/**
 * @brief Prints the value at the top of the stack.
 *
 * @param stack Pointer to linked list stack.
 * @param line_number Number of line where opcode occurs.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * @brief Removes the top element of the stack.
 *
 * @param stack Pointer to first node.
 * @param line_number Integer.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
    stack_t *node = *stack;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = node->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(node);
}

/**
 * @brief Frees a linked list.
 *
 * @param head Pointer to first node.
 */
void free_dlistint(stack_t *head)
{
    stack_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}
