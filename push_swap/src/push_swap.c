/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:37 by amayorga          #+#    #+#             */
/*   Updated: 2024/11/28 19:25:38 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;
    int *nums;

    stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack *));
    if(!stack_a)
        return (-1);
    stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack *));
    if(!stack_b)    
        return (-1);
    if(argc < 2)
    {
        ft_printf(RED"ERROR\n");
        return (-1);
    }
        

    //Paso 1: Checkear input
    nums = check_args(argc, argv, &size); 
    if(!nums)
    {
        ft_printf(RED"ERROR\n");
        return(-1);
    }

    //HACER METODOS DE PRINTEAR PARA DEBUG Y ERRORES.

    //Paso 2: Convertir input en mi estructura
    if(size <= 1 || is_duplicate(nums, size)){
        free(nums);
        ft_printf(RED"ERROR\n");
        return (-1);
    }
    init_stack(stack_a, stack_b, nums, size);
    print_stack(stack_a);
  
    //Paso 3: Ordenar numeros


    //Radix algorithm
    //Ksort algorithm -- use this
    
    return (0);

}