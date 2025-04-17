/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:01:49 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/27 15:20:40 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

t_cheapest	ft_get_lowest_b(t_stack *stack, int i)
{
	t_cheapest	cheapest;
	int			nb;
	int			result;

	nb = stack->index_b[i];
	cheapest.cost = ft_abs(nb - stack->index_a[0]);
	cheapest.pos.a = 0;
	cheapest.pos.b = i;
	i = 0;
	while (i < stack->size.a)
	{
		result = ft_abs(nb - stack->index_a[i]);
		if (result < cheapest.cost)
		{
			cheapest.cost = ft_abs(nb - stack->index_a[i]);
			cheapest.pos.a = i;
		}
		i++;
	}
	return (cheapest);
}

int	ft_is_new_lowest_b(t_stack *stack, int nb)
{
	int	i;
	int	lowest;

	i = 0;
	lowest = stack->index_a[i];
	while (i < stack->size.a)
	{
		if (stack->index_a[i] < lowest)
			lowest = stack->index_a[i];
		i++;
	}
	if (nb < lowest)
		return (1);
	return (0);
}
