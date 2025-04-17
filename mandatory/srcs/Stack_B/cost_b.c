/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:59:50 by nofanizz          #+#    #+#             */
/*   Updated: 2025/02/27 15:53:32 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cheapest	ft_get_between_b(t_stack *stack, int i)
{
	t_cheapest	cheapest;
	int			nb;
	int			result;

	nb = stack->index_b[i];
	cheapest.pos.b = i;
	i = 0;
	while ((nb - stack->index_a[i]) > 0)
		i++;
	result = ft_abs(nb - stack->index_a[i]);
	cheapest.cost = result;
	cheapest.pos.a = i;
	i = 0;
	while (i < stack->size.a)
	{
		result = ft_abs(nb - stack->index_a[i]);
		if (result < cheapest.cost && (nb - stack->index_a[i]) < 0)
		{
			cheapest.cost = result;
			cheapest.pos.a = i;
		}
		i++;
	}
	return (cheapest);
}

static t_cheapest	get_cheapest_a(t_stack *stack, int i)
{
	int			nb;
	t_cheapest	cheapest;

	nb = stack->index_b[i];
	if (ft_is_new_biggest_b(stack, nb) == 1)
		cheapest = ft_get_biggest_b(stack, i);
	else if (ft_is_new_lowest_b(stack, nb) == 1)
		cheapest = ft_get_lowest_b(stack, i);
	else
		cheapest = ft_get_between_b(stack, i);
	return (cheapest);
}

static int	cost_supp_pos(t_cheapest cheapest, t_stack *stack, int i)
{
	int	total_cost;
	int	pos;

	pos = i;
	total_cost = 0;
	if (pos <= (stack->size.a / 2) && cheapest.pos.b <= (stack->size.b / 2))
	{
		if (pos > cheapest.pos.b)
			total_cost = pos;
		else
			total_cost = cheapest.pos.b;
	}
	else if (pos <= (stack->size.a / 2) && cheapest.pos.b >= (stack->size.b
			/ 2))
		total_cost = pos + (stack->size.b - cheapest.pos.b);
	return (total_cost);
}

static t_cheapest	get_total_cost(t_cheapest cheapest, t_stack *stack, int i)
{
	int	total_cost;
	int	pos;

	pos = i;
	total_cost = 0;
	total_cost = cost_supp_pos(cheapest, stack, i);
	if (total_cost == 0)
	{
		if (pos >= (stack->size.a / 2) && cheapest.pos.b <= (stack->size.b / 2))
			total_cost = (stack->size.a - pos) + cheapest.pos.b;
		else if (pos >= (stack->size.a / 2) && cheapest.pos.b >= (stack->size.b
				/ 2))
		{
			if ((stack->size.a - pos) >= (stack->size.b - cheapest.pos.b))
				total_cost = stack->size.a - pos;
			else
				total_cost = stack->size.b - cheapest.pos.b;
		}
	}
	cheapest.cost = total_cost;
	return (cheapest);
}

t_cheapest	ft_cheapest_diff_b(t_stack *stack, int i)
{
	t_cheapest	current;
	t_cheapest	cheapest;

	i = 0;
	current = get_cheapest_a(stack, i);
	current = get_total_cost(current, stack, i);
	cheapest.cost = current.cost;
	cheapest.pos.a = current.pos.a;
	cheapest.pos.b = current.pos.b;
	while (i < stack->size.b)
	{
		current = get_cheapest_a(stack, i);
		current = get_total_cost(current, stack, i);
		if (current.cost < cheapest.cost)
		{
			cheapest.cost = current.cost;
			cheapest.pos.a = current.pos.a;
			cheapest.pos.b = current.pos.b;
		}
		i++;
	}
	return (cheapest);
}
