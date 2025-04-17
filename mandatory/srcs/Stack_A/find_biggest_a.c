/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:02:33 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/26 17:42:15 by noa              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_new_biggest_a(t_stack *stack, int nb)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = stack->index_b[i];
	while (i < stack->size.b)
	{
		if (stack->index_b[i] > biggest)
			biggest = stack->index_b[i];
		i++;
	}
	if (nb > biggest)
		return (1);
	return (0);
}

t_cheapest	ft_get_biggest_a(t_stack *stack, int i)
{
	t_cheapest	cheapest;
	int			nb;

	nb = stack->index_a[i];
	cheapest.cost = nb - stack->index_b[i];
	cheapest.pos.a = i;
	cheapest.pos.b = i;
	i = 0;
	while (i < stack->size.b)
	{
		if (nb - stack->index_b[i] < cheapest.cost)
		{
			cheapest.cost = nb - stack->index_b[i];
			cheapest.pos.b = i;
		}
		i++;
	}
	return (cheapest);
}
