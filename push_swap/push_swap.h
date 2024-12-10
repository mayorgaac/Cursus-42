#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\e[0;31m"
# define YEL "\e[0;33m"

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
# include <stddef.h>
# include <stdlib.h>
#include <limits.h>

    typedef struct s_node
    {
	    int				data;
	    int				index;
	    struct s_node	*next;
    }					t_node;

    typedef struct s_stack
    {
            t_node			*head;
            int				size;
    }   t_stack;

    //check.c
    int check_digits(char *arg, int *size);
    int *parse(char **args, int size);
    int *check_args(int argc, char **argv,  int *size);
    int is_duplicate(int *args, int count);
    int is_ordered(t_stack *stack);
    //print.c
    void print_error();
    void print_stack(t_stack *stack);
    void print_array(int *nums, int size);
    void print_args(char **args);
    //utils.c
    void init_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int size);
    void add_numbers(t_stack *stack_a, int index, int num);
    void init_sort(int *nums, int size);
    int get_index(int *nums, int num);
    int find_min(t_stack *a);
    //operations.c
    void push(t_stack *a, t_stack *b, char c);
    void swap(t_stack *stack, char c);
    void rotate(t_stack *stack, char c);
    void reverse_rotate(t_stack *stack, char c);
    void push_to_stack(t_stack *stack, int index, int num);
    int pop_from_stack(t_stack *stack);
    //order.c
    void order(t_stack *a, t_stack *b, int size);
    void order_3(t_stack *stack);
    void order_4(t_stack *a, t_stack *b);
    void order_5(t_stack *a, t_stack *b);
    void order_radix(t_stack *a, t_stack *b, int size);



#endif
