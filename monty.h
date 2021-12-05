#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LIFO 1
#define FIFO 0



#define DELIMITER " \n\t\a"

/* ERRORS*/
#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UNKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_SUB 9
#define ERROR_DIV 10
#define ERROR_DIV_ZERO 11
#define ERROR_MUL 12
#define ERROR_MOD 13
#define ERROR_STACK_EMPTY 14
#define ERROR_PCHAR_RANGE 15

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





typedef struct info_s
{
	char *cmd;
	char **arg;
	char *fn;
	int l_number;
	FILE *fp;
	int type;
} info_t;
extern info_t info;



int treat_monty(char *filename);
int split(void);
int excute_monty(stack_t **stack);



void free_info(void);
void free_list(stack_t *stack);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);

void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);


size_t getline (char **string, size_t *n, FILE *stream);

void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
void interpret_line(char *, int);
int find_func(char *opcode, char *value, int line_number);

stack_t *create_node(int n);
void print_stack(stack_t **stack, unsigned int line_number);
void add_to_stack(stack_t **stack, unsigned int line_number);
void call_fun(void (*f)(stack_t **, unsigned int), char *, char *, int);

void handle_errors(int e);

#endif /*MONTY_H_*/
