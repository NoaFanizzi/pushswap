/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:53:30 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/05 11:31:01 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < stack->size.a)
		i++;
	temp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < stack->size.b)
		i++;
	temp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
