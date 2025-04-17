/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:53:25 by noa               #+#    #+#             */
/*   Updated: 2025/02/25 16:35:58 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_b(t_cheapest *cheapest, t_stack *stack)
{
	while (cheapest->pos.a < stack->size.a && cheapest->pos.b < stack->size.b)
	{
		rrr(stack);
		ft_putstr_fd("rrr\n", 1);
		cheapest->pos.a += 1;
		cheapest->pos.b += 1;
	}
	while (cheapest->pos.a < stack->size.a)
	{
		rra(stack);
		ft_putstr_fd("rra\n", 1);
		cheapest->pos.a += 1;
	}
	while (cheapest->pos.b < stack->size.b)
	{
		rrb(stack);
		ft_putstr_fd("rrb\n", 1);
		cheapest->pos.b += 1;
	}
}

void	ft_b_l(t_cheapest *cheapest, t_stack *stack)
{
	while (cheapest->pos.a < stack->size.a)
	{
		rra(stack);
		ft_putstr_fd("rra\n", 1);
		cheapest->pos.a += 1;
	}
	while (cheapest->pos.b > 0)
	{
		rb(stack);
		ft_putstr_fd("rb\n", 1);
		cheapest->pos.b -= 1;
	}
}

void	ft_l_l(t_cheapest *cheapest, t_stack *stack)
{
	while (cheapest->pos.a > 0 && cheapest->pos.b > 0)
	{
		rr(stack);
		ft_putstr_fd("rr\n", 1);
		cheapest->pos.a -= 1;
		cheapest->pos.b -= 1;
	}
	while (cheapest->pos.a > 0)
	{
		ra(stack);
		ft_putstr_fd("ra\n", 1);
		cheapest->pos.a -= 1;
	}
	while (cheapest->pos.b > 0)
	{
		rb(stack);
		ft_putstr_fd("rb\n", 1);
		cheapest->pos.b -= 1;
	}
}

void	ft_l_b(t_cheapest *cheapest, t_stack *stack)
{
	while (cheapest->pos.a > 0)
	{
		ra(stack);
		ft_putstr_fd("ra\n", 1);
		cheapest->pos.a -= 1;
	}
	while (cheapest->pos.b < stack->size.b)
	{
		rrb(stack);
		ft_putstr_fd("rrb\n", 1);
		cheapest->pos.b += 1;
	}
}

void	ft_arrange(t_cheapest *cheapest, t_stack *stack)
{
	if (cheapest->pos.a <= (stack->size.a / 2)
		&& cheapest->pos.b <= (stack->size.b / 2))
		ft_l_l(cheapest, stack);
	if (cheapest->pos.a <= (stack->size.a / 2)
		&& cheapest->pos.b > (stack->size.b / 2))
		ft_l_b(cheapest, stack);
	if (cheapest->pos.a > (stack->size.a / 2)
		&& cheapest->pos.b > (stack->size.b / 2))
		ft_b_b(cheapest, stack);
	if (cheapest->pos.a > (stack->size.a / 2)
		&& cheapest->pos.b <= (stack->size.b / 2))
		ft_b_l(cheapest, stack);
}
