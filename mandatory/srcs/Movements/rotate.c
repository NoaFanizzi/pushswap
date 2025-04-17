/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:41:30 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/25 16:35:08 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->index_a[i];
	while (i + 1 < stack->size.a)
	{
		stack->index_a[i] = stack->index_a[i + 1];
		i++;
	}
	stack->index_a[i] = temp;
}

void	rb(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->index_b[i];
	while (i + 1 < stack->size.b)
	{
		stack->index_b[i] = stack->index_b[i + 1];
		i++;
	}
	stack->index_b[i] = temp;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
