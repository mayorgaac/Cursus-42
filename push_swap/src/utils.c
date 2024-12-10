/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:31 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/28 21:08:18 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//**********UTILS STACKS**************/

void init_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int size)
{
    int i;
    t_node *tmp;

    stack_a->head = NULL;
    stack_a->size = 0;
    stack_b->head = NULL;
    stack_b->size = 0;
    i = size - 1;
    while(i >= 0)
    {
        push_to_stack(stack_a, 0, nums[i]);
        i--;
    }
    init_sort(nums,size);
    tmp = stack_a->head;
    while(tmp)
    {
        tmp->index = get_index(nums, tmp->data);
        tmp = tmp->next;
    }

}

void init_sort(int *nums, int size)
{
    int number;
    int i;
    int j;

    i = 1;
    while(i < size)
    {
        number = nums[i];
        j = i - 1;
        while( j >= 0 && nums[j] > number )
        {
            nums[j + 1] = nums[j];
            j--;

        }
        nums[j + 1] = number;
        i++;
    }
}

int get_index(int *nums, int num)
{
    int i;

    i = 0;
    while(nums[i] != num)
        i++;
    return (i);
}

int find_min(t_stack *a)
{
  t_node *current;

  current = a->head;
  while(current)
  {
    if(current->index == 0)
      return (current->data);
    current = current->next;
  }
}
