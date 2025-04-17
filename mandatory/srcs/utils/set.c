/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:56:09 by noa               #+#    #+#             */
/*   Updated: 2025/02/27 11:19:19 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_top(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->index_a[i] != stack->size.a)
		i++;
	if (i <= (stack->size.a / 2))
	{
		while (i > 0)
		{
			ra(stack);
			ft_putstr_fd("ra\n", 1);
			i--;
		}
		ra(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		while (i + 1 < stack->size.a)
		{
			rra(stack);
			ft_putstr_fd("rra\n", 1);
			i++;
		}
	}
}
