/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_allocation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:26:56 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/10 17:34:20 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_all(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->index_a)
		free(stack->index_a);
	if (stack->index_b)
		free(stack->index_b);
}

int	ft_index_allocation_bonus(t_stack *stack, int argc)
{
	stack->index_a = ft_calloc((argc), sizeof(int));
	if (!(stack->index_a))
	{
		ft_free_all(stack);
		return (0);
	}
	stack->index_b = ft_calloc((argc), sizeof(int));
	if (!(stack->index_b))
	{
		ft_free_all(stack);
		return (0);
	}
	return (1);
}

int	ft_stack_allocation_bonus(t_stack *stack, int argc)
{
	stack->a = ft_calloc((argc + 2), sizeof(int));
	if (!(stack->a))
	{
		ft_free_all(stack);
		return (0);
	}
	stack->b = ft_calloc((argc + 2), sizeof(int));
	if (!(stack->b))
	{
		ft_free_all(stack);
		return (1);
	}
	return (1);
}
