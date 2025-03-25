/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:31 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/10 20:28:02 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **nums, int size)
{
	int		i;
	t_node	*tmp;

	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
	i = size - 1;
	while (i >= 0)
	{
		push_to_stack(stack_a, 0, ft_atoi(nums[i]));
		i--;
	}
	init_sort(nums, size);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->index = get_index(nums, tmp->data);
		tmp = tmp->next;
	}
	ft_free(nums);
}

void	init_sort(char **nums, int size)
{
	int		number;
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < size)
	{
		number = ft_atoi(nums[i]);
		j = i - 1;
		while (j >= 0 && ft_atoi(nums[j]) > number)
		{
			tmp = nums[j + 1];
			nums[j + 1] = nums[j];
			nums[j] = tmp;
			j--;
		}
		i++;
	}
}

int	get_index(char **nums, int num)
{
	int		i;
	char	*tmp_num;

	i = 0;
	tmp_num = ft_itoa(num);
	if (!tmp_num)
		return (-1);
	while (nums[i] != NULL)
	{
		if (ft_strncmp(nums[i], tmp_num, 100) == 0)
		{
			free(tmp_num);
			return (i);
		}
		i++;
	}
	free(tmp_num);
	return (-1);
}

int	get_min_value(t_stack *stack)
{
	t_node	*tmp;
	int		minimun;

	tmp = stack->head->next;
	minimun = stack->head->data;
	while (tmp)
	{
		if (tmp->data < minimun)
			minimun = tmp->data;
		tmp = tmp->next;
	}
	return (minimun);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*tmp;
	int		position;

	tmp = stack->head;
	position = 0;
	while (tmp)
	{
		if (tmp->data == value)
			break ;
		tmp = tmp->next;
		position++;
	}
	return (position);
}
