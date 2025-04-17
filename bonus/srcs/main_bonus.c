/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:44:32 by noa               #+#    #+#             */
/*   Updated: 2025/03/14 10:27:56 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_swap(char *buffer, t_stack *stack)
{
	if (ft_strncmp(buffer, "sa\n", 3) == 0 && ft_strlen(buffer) == 3)
	{
		sa(stack->a);
		return (1);
	}
	else if (ft_strncmp(buffer, "sb\n", 3) == 0 && ft_strlen(buffer) == 3)
	{
		sb(stack->b);
		return (1);
	}
	else if (ft_strncmp(buffer, "ss\n", 3) == 0 && ft_strlen(buffer) == 3)
	{
		ss(stack->a, stack->b);
		return (1);
	}
	return (0);
}

int	ft_check_instructions(char *buffer, t_stack *stack)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0 && ft_strlen(buffer) == 3)
	{
		pa(stack->a, stack->b, stack->size);
		stack->size.a += 1;
		stack->size.b -= 1;
	}
	else if (ft_strncmp(buffer, "pb\n", 3) == 0 && ft_strlen(buffer) == 3)
	{
		pb(stack->a, stack->b, stack->size);
		stack->size.a -= 1;
		stack->size.b += 1;
	}
	else if (ft_strncmp(buffer, "ra\n", 3) == 0 && ft_strlen(buffer) == 3)
		ra(stack);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0 && ft_strlen(buffer) == 3)
		rb(stack);
	else if (ft_strncmp(buffer, "rra\n", 4) == 0 && ft_strlen(buffer) == 4)
		rra(stack);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0 && ft_strlen(buffer) == 4)
		rrb(stack);
	else if (!ft_check_swap(buffer, stack))
		return (0);
	return (1);
}

void	ft_check_final_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size.b != 0)
	{
		ft_putstr_fd("KO\n", 2);
		return ;
	}
	while (i < stack->size.a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			ft_putstr_fd("KO\n", 2);
			free(stack->a);
			free(stack->b);
			return ;
		}
		i++;
	}
	ft_putstr_fd("OK\n", 2);
	free(stack->a);
	free(stack->b);
	return ;
}

void	ft_checker(int argc, char **argv)
{
	char	*buffer;
	t_stack	stack;

	if (ft_parse(argv, argc) == 1)
		return ;
	if (ft_get_stack(&stack, argc, argv) == 0)
		return ;
	buffer = get_next_line(0);
	while (buffer)
	{
		if (ft_check_instructions(buffer, &stack) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(buffer);
			return ;
		}
		free(buffer);
		buffer = get_next_line(0);
	}
	ft_check_final_stack(&stack);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ft_checker(argc, argv);
}
