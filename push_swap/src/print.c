/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:40 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/28 19:25:41 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->head;
    while(tmp)
    {
        ft_printf("Index: %d; Number: %d\n", tmp->index, tmp->data);
        tmp = tmp->next;
    }
}

void print_array(int *nums, int size)
{
    int i = 0;

    while(i < size)
    {
        ft_printf("Num: %d\n",nums[i]);
        i++;
    }
}

void print_args(char **args)
{
    int i = 0;

    while(args[i])
    {
        ft_printf("Arg: %s\n",args[i]);
        i++;
    }
}