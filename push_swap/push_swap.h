/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:06:56 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/12 21:06:18 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\e[0;31m"
# define YEL "\e[0;33m"

# include "Libft/libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;
//check.c
int		check(int argc, char ***nums, char **argv, int *size);
int		check_digits(int argc, char **arg, int *size);
int		check_range(char *s_num);
char	**parse(char **args, char **numbers);
char	**check_args(char **argv, int *size);
//print.c
void	print_error(void);
void	print_stack(t_stack *stack, char *name);
void	print_array(int *nums, int size);
void	print_args(char **args);
//utils.c
void	init_stack(t_stack *stack_a, t_stack *stack_b, char **nums, int size);
void	init_sort(char **nums, int size);
int		get_index(char **nums, int num);
int		get_min_value(t_stack *stack);
int		get_position(t_stack *stack, int value);
//utils_v2.c
int		choose_pivot(t_stack *a);
int		ft_sqrt(int number);
void	ft_free(char **res);
void	ft_free_stack(t_stack *stack);
//utils_v3.c
int		is_duplicate(char **args, int count);
int		get_max_bits(t_stack *a);
//operations.c
void	push(t_stack *a, t_stack *b, char c);
void	swap(t_stack *stack, char c);
void	rotate(t_stack *stack, char c);
void	rotate_combined(t_stack *a, t_stack *b);
//operations_v2.c
void	reverse_rotate(t_stack *stack, char c);
void	reverse_rotate_combined(t_stack *a, t_stack *b);
void	push_to_stack(t_stack *stack, int index, int num);
int		pop_from_stack(t_stack *stack);
//sort.c
void	sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
void	sort3(t_stack *stack);
void	push_smallest_to_b(t_stack *a, t_stack *b);
void	sort4(t_stack *a, t_stack *b);
//sort_v2.c
void	sort5(t_stack *a, t_stack *b);
int		count_rot(t_stack *stack, int max_index);
void	ft_constant_sort(t_stack *stack_a, t_stack *stack_b, int digits);
void	great_sort(t_stack *stack_a, t_stack *stack_b, int digits);

#endif