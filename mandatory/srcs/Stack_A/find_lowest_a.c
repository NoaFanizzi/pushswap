/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:01:49 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/27 15:20:48 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	ft_get_lowest_a(t_stack *stack, int i)
{
	t_cheapest	cheapest;
	int			nb;
	int			result;

	nb = stack->index_a[i];
	cheapest.cost = ft_abs(nb - stack->index_b[0]);
	cheapest.pos.a = i;
	cheapest.pos.b = 0;
	i = 0;
	while (i < stack->size.b)
	{
		result = ft_abs(nb - stack->index_b[i]);
		if (result > cheapest.cost)
		{
			cheapest.cost = ft_abs(nb - stack->index_b[i]);
			cheapest.pos.b = i;
		}
		i++;
	}
	return (cheapest);
}

int	ft_is_new_lowest_a(t_stack *stack, int nb)
{
	int	i;
	int	lowest;

	i = 0;
	lowest = stack->index_b[i];
	while (i < stack->size.b)
	{
		if (stack->index_b[i] < lowest)
			lowest = stack->index_b[i];
		i++;
	}
	if (nb < lowest)
		return (1);
	return (0);
}
