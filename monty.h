#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
*struct lists - struct contains string line and its parts
*@arg1: opcode
*@arg2: number
*@line: string line
*@f: pointer to FILE
*
*Description: instruction line and its parts
*/
typedef struct lists
{
	char *arg1;
	char *arg2;
	char *line;
	FILE *f;
} list_t;

extern list_t list_args;

/*  functions  ******************/
int parse_string(FILE *fp, stack_t **s);
int check_empty(char *line);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
stack_t  *add_dnodeint(stack_t **head, const int n);
void  free_stack(stack_t **h);
void print_stack(const stack_t *h);
void int_err(int line_number);
int is_num(char *str);
#endif
