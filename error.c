#include "monty.h"
/**
 * 
*/
void int_err(int line_number)
{
    fprintf(stderr, "L %d: usage: push integer\n", line_number );
    free(list_args.line);
    fclose(list_args.f);
    exit(EXIT_FAILURE);
}