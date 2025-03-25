/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:13:37 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/05 16:13:38 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//El ultimmo elemento del stack se convierte en el primero
void	reverse_rotate(t_stack *stack, char c)
{
	t_node	*node;
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = stack->head;
	stack->head = node;
	if (c == 'r')
		return ;
	ft_printf("rr%c\n", c);
}

void	reverse_rotate_combined(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'r');
	reverse_rotate(b, 'r');
	ft_printf("rrr\n");
}

//Añade un elemento al stack dejandolo el primero
void	push_to_stack(t_stack *stack, int index, int num)
{
	t_node	*tmp;

	tmp = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = num;
	tmp->index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

//Elimina el primer elemento del stack.
//Return valor del elemento eliminado.
int	pop_from_stack(t_stack *stack)
{
	t_node	*node;
	int		data;

	if (!stack->head)
		exit(-1);
	node = stack->head;
	stack->head = node->next;
	data = node->data;
	free(node);
	node = NULL;
	stack->size--;
	return (data);
}
