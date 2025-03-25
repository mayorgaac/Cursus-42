/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:37 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/12 18:09:44 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	char	**nums;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (-1);
	stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (-1);
	if (-1 == check(argc, &nums, argv, &size))
		return (ft_free_stack(stack_a), ft_free_stack(stack_b), 0);
	init_stack(stack_a, stack_b, nums, size);
	sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
