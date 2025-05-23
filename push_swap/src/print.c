/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:40 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/04 20:32:48 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	t_node	*tmp;

	tmp = stack->head;
	if (tmp)
		ft_printf("%s: [%d,", name, tmp->data);
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
			ft_printf("%d,", tmp->data);
	}
	ft_printf("]\n");
}

void	print_array(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("Num: %d\n", nums[i]);
		i++;
	}
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_printf("Arg: %s\n", args[i]);
		i++;
	}
}
