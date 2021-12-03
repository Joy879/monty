#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>



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


void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
void interpret_line(char *, int);
int find_func(char *opcode, char *value, int line_number);

stack_t *create_node(int n);
void print_stack(stack_t **stack, unsigned int line_number);
void add_to_stack(stack_t **stack, unsigned int line_number);
void call_fun(void (*f)(stack_t **, unsigned int), char *, char *, int)
#endif /*MONTY_H_*/
