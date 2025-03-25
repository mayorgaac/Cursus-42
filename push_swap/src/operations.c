/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:43 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/05 16:13:18 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Coge el primer elemento del stack a y lo pone el primero en el stack b
//Hay que poner la letra del segundo stack
void	push(t_stack *a, t_stack *b, char c)
{
	int	index;

	if (a->head == NULL)
		return ;
	index = a->head->index;
	push_to_stack(b, index, pop_from_stack(a));
	ft_printf("p%c\n", c);
}

//Intercambia los dos primeros elementos del stack
void	swap(t_stack *stack, char c)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	ft_printf("s%c\n", c);
}

//El primer elemento del stack se convierte en el ultimo
void	rotate(t_stack *stack, char c)
{
	t_node	*node;
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	node = stack->head;
	stack->head = node->next;
	tmp = stack->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	node->next = NULL;
	tmp->next = node;
	if (c == 'r')
		return ;
	ft_printf("r%c\n", c);
}

void	rotate_combined(t_stack *a, t_stack *b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}
