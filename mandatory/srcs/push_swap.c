/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:12:12 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/14 10:16:10 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_many(char **args, int argc)
{
	t_stack	stack;

	stack = (t_stack){NULL, NULL, NULL, NULL, (t_size){0, 0}};
	if (!ft_stack_allocation(&stack, argc) || !ft_index_allocation(&stack,
			argc))
		return ;
	load_stack(stack.a, args);
	stack.size.a = argc - 1;
	stack.size.b = 0;
	if (!ft_sort(&stack))
	{
		ft_free_all(&stack);
		return ;
	}
	ft_free_all(&stack);
}

static void	ft_sort_two(char **args)
{
	if (ft_atoi(args[1]) > ft_atoi(args[2]))
		ft_putstr_fd("ra\n", 1);
}

static void	ft_sort_three(char **args)
{
	int	a;
	int	b;
	int	c;

	a = ft_atoi(args[1]);
	b = ft_atoi(args[2]);
	c = ft_atoi(args[3]);
	if ((a > b) && (a < c && b < c))
		ft_putstr_fd("sa\n", 1);
	if ((a > b) && (a > c && b > c))
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("rra\n", 1);
	}
	if ((a > b) && (a > c && b < c))
		ft_putstr_fd("ra\n", 1);
	if ((a < b) && (a > c && b > c))
		ft_putstr_fd("rra\n", 1);
	if ((a < b) && (a < c && b > c))
	{
		ft_putstr_fd("sa\n", 1);
		ft_putstr_fd("ra\n", 1);
	}
}

int	ft_check_order(char **args, int argc)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	a = 0;
	b = 0;
	while (i < argc - 1)
	{
		a = ft_atoi(args[i]);
		b = ft_atoi(args[i + 1]);
		if (a > b)
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_swap(char **args, int argc)
{
	if (!(args))
		return ;
	if (ft_parse(args, argc) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (ft_check_order(args, argc) == 0)
		return ;
	if (argc == 3)
		ft_sort_two(args);
	if (argc == 4)
		ft_sort_three(args);
	if (argc > 4)
		ft_sort_many(args, argc);
}
