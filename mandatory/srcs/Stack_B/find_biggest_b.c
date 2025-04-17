/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:02:33 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/27 11:40:30 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_new_biggest_b(t_stack *stack, int nb)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = stack->index_a[i];
	while (i < stack->size.a)
	{
		if (stack->index_a[i] > biggest)
			biggest = stack->index_a[i];
		i++;
	}
	if (nb > biggest)
		return (1);
	return (0);
}

t_cheapest	ft_get_biggest_b(t_stack *stack, int i)
{
	t_cheapest	cheapest;
	int			nb;

	nb = stack->index_b[i];
	cheapest.cost = nb - stack->index_a[i];
	cheapest.pos.a = i;
	cheapest.pos.b = i;
	i = 0;
	while (i < stack->size.a)
	{
		if (nb - stack->index_a[i] > cheapest.cost)
		{
			cheapest.cost = nb - stack->index_a[i];
			cheapest.pos.a = i;
		}
		i++;
	}
	return (cheapest);
}
