#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/

/**
 * struct global_var - Global variables for the Monty interpreter
 * @file: File pointer
 * @push_arg: Argument for the push instruction
 * @buffer: Buffer pointer
 * Description: Holds global variables for Monty interpreter
 */
typedef struct global_var
{
    FILE *file;
    int push_arg;
    char *buffer;
} global_var;

extern global_var var_global;

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer value
 * @prev: Pointer to the previous element of the stack
 * @next: Pointer to the next element of the stack
 * Description: Structure for a doubly linked list node in a stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function pointer to handle the opcode
 * Description: Structure to hold an opcode and its associated function
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/* Monty Functions */
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* Custom Functions */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* String ASCII Functions */
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

/* Math Functions */
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* Utility Functions */
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

#endif
