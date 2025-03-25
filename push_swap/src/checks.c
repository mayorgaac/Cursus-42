/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayorga <amayorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:25:49 by amayorga          #+#    #+#             */
/*   Updated: 2025/03/12 21:08:48 by amayorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check(int argc, char ***nums, char **argv, int *size)
{
	*size = 0;
	if (!check_digits(argc, argv, size))
	{
		ft_printf(RED"ERROR\n");
		return (-1);
	}
	if (argc <= 2)
		return (-1);
	*nums = check_args(argv, size);
	if (!(*nums))
	{
		ft_printf(RED"ERROR\n");
		return (-1);
	}
	if ((*size) <= 1 || is_duplicate((*nums), (*size)))
	{
		ft_free(*nums);
		ft_printf(RED"ERROR\n");
		return (-1);
	}
	return (0);
}

int	check_digits(int argc, char **arg, int *size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		(*size) += ft_count_words(arg[i], ' ');
		while (j < ft_strlen(arg[i]))
		{
			if (arg[i][j] != ' '
				&& arg[i][j] != '\n'
				&& !ft_isdigit(arg[i][j])
				&& arg[i][j] != '-'
				&& arg[i][j] != '+'
				&& arg[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range(char *s_num)
{
	long	num;

	num = ft_atol(s_num);
	if (ft_strncmp(s_num, "0", 1) == 0)
		return (1);
	if (num == 0)
		return (0);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

char	**parse(char **args, char **numbers)
{
	int		c;
	int		i;
	int		k;
	char	**tmp_args;

	c = 1;
	k = 0;
	while (args[c])
	{
		tmp_args = ft_split(args[c], ' ');
		if (!tmp_args)
			return (ft_free(numbers), NULL);
		i = 0;
		while (tmp_args[i])
		{
			if (!check_range(tmp_args[i]))
				return (ft_free(tmp_args), ft_free(numbers), NULL);
			numbers[k++] = ft_strdup(tmp_args[i++]);
		}
		ft_free(tmp_args);
		c++;
	}
	return (numbers);
}

char	**check_args(char **argv, int *size)
{
	char	**numbers;

	numbers = (char **)ft_calloc((*size) + 1, sizeof(char *));
	if (numbers == NULL)
		return (NULL);
	if (parse(argv, numbers) == NULL)
		return (NULL);
	return (numbers);
}
