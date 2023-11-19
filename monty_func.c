#include "monty.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

/**
 * Rest of your function declarations and global variables...
 */

/**
 * @brief Parses a line for an opcode and arguments.
 *
 * @param line The line to be parsed.
 * @param stack Pointer to the head of the stack.
 * @param line_number The current line number.
 * @return Returns the opcode or NULL on failure.
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number) {
    char *op_code, *push, *arg;
    (void)stack;

    push = "push";
    op_code = strtok(line, "\n ");
    if (op_code == NULL)
        return NULL;

    if (strcmp(op_code, push) == 0) {
        arg = strtok(NULL, "\n ");
        if (arg != NULL) {
            int number = atoi(arg);
            if (number != 0 || strcmp(arg, "0") == 0) {
                var_global.push_arg = number;
            } else {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "L%d: usage: push requires an argument\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    return op_code;
}


/**
 * @brief Checks if a string is a number.
 *
 * @param str The string being checked.
 * @return Returns 1 if the string is a number, 0 otherwise.
 */
int isnumber(char *str) {
    unsigned int i = 0;

    if (str == NULL)
        return (0);

    while (str[i]) {
        if (str[0] == '-') {
            i++;
            continue;
        }
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) 
{
    size_t capacity = 128;
    size_t index = 0;
    int ch;

    if (*lineptr == NULL) 
    {
        *lineptr = malloc(capacity * sizeof(char));
        if (*lineptr == NULL) 
        {
            return (-1);
        }
        *n = capacity;
    }

    while ((ch = fgetc(stream)) != EOF && ch != '\n') 
    {
        (*lineptr)[index++] = (char)ch;
        if (index >= *n) {
            *n += capacity;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL) 
            {
                return (-1);
            }
        }
    }

    if (ch == EOF && index == 0) 
    {
        return (-1);
    }

    (*lineptr)[index] = '\0';
    return (index);
}


/**
 * @brief Reads a bytecode file and runs commands.
 *
 * @param filename The pathname to the file.
 * @param stack Pointer to the top of the stack.
 */
void read_file(char *filename, stack_t **stack) {
    int check;
    char *line;
    size_t i = 0;
    int line_count = 1;
    instruct_func s;
    int read;

    var_global.file = fopen(filename, "r");

    if (var_global.file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = _getline(&var_global.buffer, &i, var_global.file)) != -1) {
        line = parse_line(var_global.buffer, stack, line_count);
        if (line == NULL || line[0] == '#') {
            line_count++;
            continue;
        }
        s = get_op_func(line);
        if (s == NULL) {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
            exit(EXIT_FAILURE);
        }
        s(stack, line_count);
        line_count++;
    }

    free(var_global.buffer);
    check = fclose(var_global.file);
    if (check == -1)
        exit(-1);
}

/**
 * @brief Checks opcode and returns the correct function.
 *
 * @param str The opcode.
 * @return Returns a function or NULL on failure.
 */
instruct_func get_op_func(char *str) {
    int i = 0;

    instruction_t instruct[] = {
        {"push", _push},
        {"pall", _pall},
        /* ... other instruction mappings ... */
        {NULL, NULL},
    };

    while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0) {
        i++;
    }

    return (instruct[i].f);
}
