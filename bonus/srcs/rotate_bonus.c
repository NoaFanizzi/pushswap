/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:41:30 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/05 11:29:15 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->a[i];
	while (i + 1 < stack->size.a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void	rb(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->b[i];
	while (i + 1 < stack->size.b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
