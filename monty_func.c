#include "monty.h"

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
        return (NULL);

    if (strcmp(op_code, push) == 0) {
        arg = strtok(NULL, "\n ");
        if (isnumber(arg) == 1 && arg != NULL) {
            var_global.push_arg = atoi(arg);
        } else {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    return (op_code);
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

/**
 * @brief Reads a bytecode file and runs commands.
 *
 * @param filename The pathname to the file.
 * @param stack Pointer to the top of the stack.
 */
void read_file(char *filename, stack_t **stack) {
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

    while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1) {
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
    int check = fclose(var_global.file);
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
