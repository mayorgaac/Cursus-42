/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:11:36 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/05 16:15:06 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	else if (a->size == 2)
		swap(a, 'a');
	else if (a->size == 3)
		sort3(a);
	else if (a->size == 4)
		sort4(a, b);
	else if (a->size == 5)
		sort5(a, b);
	else
		great_sort(a, b, a->size);
}

int	is_sorted(t_stack *a)
{
	t_node	*temp;

	temp = a->head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort3(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data
		&& stack->head->data > stack->head->next->next->data)
		rotate(stack, 'a');
	if (stack->head->next->data > stack->head->data
		&& stack->head->next->data > stack->head->next->next->data)
		reverse_rotate(stack, 'a');
	if (stack->head->data > stack->head->next->data)
		swap(stack, 'a');
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_value;
	int	position;

	min_value = get_min_value(a);
	position = get_position(a, min_value);
	if (position < a->size / 2)
	{
		while (a->head->data != min_value)
			rotate(a, 'a');
	}
	else
	{
		while (a->head->data != min_value)
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
}

void	sort4(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort3(a);
	push(b, a, 'a');
}
