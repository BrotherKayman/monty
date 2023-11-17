#include "monty.h"

global_var var_global;

/**
 * @brief main - Entry point for the Monty program
 * @param ac: Number of command-line arguments
 * @param av: Array of command-line argument strings
 * Return: Always 0 on success
 */
int main(int ac, char **av) 
{
    stack_t *stack = NULL;

    if (ac != 2) 
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    read_file(av[1], &stack);

    free_dlistint(stack);
    
    return (EXIT_SUCCESS);
}
