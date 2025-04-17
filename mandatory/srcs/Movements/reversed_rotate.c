/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:53:30 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/25 16:35:23 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < stack->size.a)
		i++;
	temp = stack->index_a[i];
	while (i > 0)
	{
		stack->index_a[i] = stack->index_a[i - 1];
		i--;
	}
	stack->index_a[i] = temp;
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < stack->size.b)
		i++;
	temp = stack->index_b[i];
	while (i > 0)
	{
		stack->index_b[i] = stack->index_b[i - 1];
		i--;
	}
	stack->index_b[i] = temp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
