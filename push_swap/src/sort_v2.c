/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:20 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/05 16:15:21 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort5(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort3(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

int	count_rot(t_stack *stack, int max_index)
{
	int		counter;
	t_node	*current;

	counter = 0;
	current = stack->head;
	while (current && current->index != max_index)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}

void	ft_constant_sort(t_stack *stack_a, t_stack *stack_b, int digits)
{
	int	i;
	int	constant_range;

	i = 0;
	constant_range = ft_sqrt(digits) * 7 / 5;
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			push(stack_a, stack_b, 'b');
			if (stack_b->size > 1)
				rotate(stack_b, 'b');
			i++;
		}
		else if (stack_a->head->index <= i + constant_range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	great_sort(t_stack *stack_a, t_stack *stack_b, int digits)
{
	int	rotate_b_count;
	int	rev_rot_b_count;

	ft_constant_sort(stack_a, stack_b, digits);
	while (digits - 1 >= 0)
	{
		rotate_b_count = count_rot(stack_b, digits - 1);
		rev_rot_b_count = stack_b->size - rotate_b_count;
		if (rotate_b_count <= rev_rot_b_count)
		{
			while (stack_b->head->index != digits - 1)
				rotate(stack_b, 'b');
		}
		else
		{
			while (stack_b->head->index != digits - 1)
				reverse_rotate(stack_b, 'b');
		}
		push(stack_b, stack_a, 'a');
		digits--;
	}
}
