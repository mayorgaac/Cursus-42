/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:43 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/28 21:10:39 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_stack *a, t_stack *b, char c)
{
    int index;
    
    if(a->head == NULL)
        return;
    index = a->head->index;
    push_to_stack(b, index, pop_from_stack(a));

    ft_printf("p%c\n", c);
}

void swap(t_stack *stack, char c)
{
    t_node *tmp;

    if(stack->head == NULL || stack->head->next == NULL)
        return;
    tmp = stack->head;
    stack->head = tmp->next;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    
    ft_printf("s%c\n", c);
}

void rotate(t_stack *stack, char c)
{
    t_node *node;
    t_node *tmp;

    if(stack->head == NULL || stack->head->next == NULL)
        return;
    node = stack->head;
    stack->head = node->next;
    tmp = stack->head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    node->next = NULL;
    tmp->next = node;

    ft_printf("r%c\n", c);
}

void reverse_rotate(t_stack *stack, char c)
{
    t_node *node;
    t_node *tmp;

    if(stack->head == NULL || stack->head->next == NULL)
        return;
    tmp = stack->head;
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    node = tmp->next;
    tmp->next = NULL;
    node->next = stack->head;
    stack->head = node;
    
    ft_printf("rr%c\n", c);
}

void push_to_stack(t_stack *stack, int index, int num)
{
    t_node *tmp;

    tmp = (t_node *)ft_calloc(1, sizeof(t_node *));
    if(!tmp)
        return;
    tmp->data = num;
    tmp->index = index;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
}

int pop_from_stack(t_stack *stack)
{
    t_node *node;
    int data;
    
    if(!stack->head)
        exit(-1);
    node = stack->head;
    stack->head = node->next;
    data = node->data;
    free(node);
    node = NULL;
    stack->size--;
    return (data);
}