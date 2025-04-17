/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:48 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/14 10:18:15 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_get_stack(t_stack *stack, int argc, char **argv)
{
	stack->a = ft_calloc((argc + 1), sizeof(int));
	if (!stack->a)
		return (0);
	stack->b = ft_calloc((argc + 1), sizeof(int));
	if (!(stack->b))
	{
		free(stack->a);
		return (0);
	}
	stack->size.a = argc - 1;
	stack->size.b = 0;
	load_stack(stack->a, argv);
	return (1);
}

void	ft_reorder(int *stack, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (stack)
	{
		while (i < size)
		{
			stack[j] = stack[i];
			i++;
			j++;
		}
		stack[j] = 0;
	}
}

void	pb(int *stack_a, int *stack_b, t_size size)
{
	int	i;

	i = 0;
	if (stack_a[i])
	{
		while (i <= size.b)
			i++;
		while (i > 0)
		{
			stack_b[i] = stack_b[i - 1];
			i--;
		}
		stack_b[i] = stack_a[0];
		ft_reorder(stack_a, size.a);
	}
}

void	pa(int *stack_a, int *stack_b, t_size size)
{
	int	i;

	i = 0;
	if (stack_b[i])
	{
		while (i <= size.a)
			i++;
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[i] = stack_b[0];
		ft_reorder(stack_b, size.b);
	}
}
