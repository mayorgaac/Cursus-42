/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:49 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/28 19:25:58 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_digits(char *arg, int *size)
{
    int i;

    i = 0;
    (*size) += ft_count_words(arg, ' ');
    while(i < ft_strlen(arg))
        {
            if(arg[i] != ' ' && !ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+' && arg[i] != '\0')
                return (0);
            i++;
        }
    return (1);

}

int check_range(char *s_num)
{
    long num;

    num = ft_atol(s_num);
    if(num > INT_MAX || num < INT_MIN)
        return (0);
    return (1);
}

int *parse(char **args, int size)
{
    int c;
    int i;
    int k;
    char **tmp_args;
    int *numbers;

    c = 1;
    k = 0;
    numbers = (int *)ft_calloc((size) + 1, sizeof(int));
    if(numbers == NULL)
        return (NULL);
    while(args[c])
    {
        tmp_args = ft_split(args[c], ' ');
        i = 0;
        while(tmp_args[i])
        {
            if(!check_range(tmp_args[i]))
                return (NULL);
            numbers[k++] = ft_atoi(tmp_args[i++]);
        }

        c++;
    }
    return (numbers);
}

int *check_args(int argc, char **argv, int *size)
{
    int i;
    int *numbers;

    i = 1;
    *size = 0;
    while(i < argc)
    {
        if(!check_digits(argv[i], size))
            return (NULL);
        i++;
    }
    numbers = parse(argv, *size);

    return (numbers);
}

int is_duplicate(int *args, int count)
{
    int i;
    int j;

    i = 0;
    while(i < count)
    {
        j = i + 1;
        while(j < count)
        {
            if(args[i] == args[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_ordered(t_stack *stack)
{
  t_node *node;
  int current_num;

  node = stack->head->next;
  current_num = stack->head->data;
  while(node)
  {
    if(node->data < current_num)
      return (0);
    current_num = node->data;
    node = node->next;
  }
  return (1);
}
