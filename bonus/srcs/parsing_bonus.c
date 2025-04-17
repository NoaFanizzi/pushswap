/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:25:32 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/11 17:56:30 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_double(char **stack)
{
	int		temp_i;
	int		temp_j;
	size_t	i;
	size_t	j;

	i = 1;
	j = 2;
	while (stack[i])
	{
		while (stack[j])
		{
			temp_i = ft_atoi(stack[i]);
			temp_j = ft_atoi(stack[j]);
			if (temp_i == temp_j)
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_check_letters(char **stack)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (stack[i])
	{
		while (stack[i][j])
		{
			if ((stack[i][j] == '-' || stack[i][j] == '+') && (j == 0))
				j++;
			if (ft_isdigit(stack[i][j]) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_check_limits(char **stack)
{
	size_t		i;
	long int	nb;

	i = 1;
	nb = 0;
	while (stack[i])
	{
		nb = ft_atol(stack[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	ft_null_check(char **stack, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!stack[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse(char **stack, int argc)
{
	if ((ft_check_letters(stack) || ft_check_double(stack))
		|| (ft_check_limits(stack) || ft_null_check(stack, argc)))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
