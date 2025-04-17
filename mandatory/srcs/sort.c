/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:59:39 by noa               #+#    #+#             */
/*   Updated: 2025/02/27 16:23:07 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_over_second(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->index_a[0];
	b = stack->index_a[1];
	c = stack->index_a[2];
	if (a < c && b < c)
	{
		sa(stack->index_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (a > c && b > c)
	{
		sa(stack->index_a);
		rra(stack);
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
	}
	else if (a > c && b < c)
	{
		ra(stack);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_sort_three_int(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->index_a[0];
	b = stack->index_a[1];
	c = stack->index_a[2];
	if (a > b)
		ft_first_over_second(stack);
	else
	{
		if ((a < b) && (a > c && b > c))
		{
			rra(stack);
			ft_putstr_fd("rra\n", 1);
		}
		if ((a < b) && (a < c && b > c))
		{
			sa(stack->index_a);
			ra(stack);
			ft_putstr_fd("sa\n", 1);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	ft_sort_in_b(t_stack *stack)
{
	t_cheapest	cheapest;

	while (stack->size.a > 3)
	{
		cheapest = ft_cheapest_diff_a(stack, 0);
		ft_arrange(&cheapest, stack);
		pb(stack->index_a, stack->index_b, stack->size);
		stack->size.a -= 1;
		stack->size.b += 1;
	}
}

void	ft_sort_in_a(t_stack *stack)
{
	t_cheapest	cheapest;

	while (stack->size.b > 0)
	{
		cheapest = ft_cheapest_diff_b(stack, 0);
		ft_arrange(&cheapest, stack);
		pa(stack->index_a, stack->index_b, stack->size);
		stack->size.a += 1;
		stack->size.b -= 1;
	}
}

int	ft_sort(t_stack *stack)
{
	if (ft_get_index(stack) == 0)
		return (0);
	pb(stack->index_a, stack->index_b, stack->size);
	stack->size.a -= 1;
	stack->size.b += 1;
	pb(stack->index_a, stack->index_b, stack->size);
	stack->size.a -= 1;
	stack->size.b += 1;
	ft_sort_in_b(stack);
	ft_sort_three_int(stack);
	ft_sort_in_a(stack);
	ft_set_top(stack);
	return (1);
}
