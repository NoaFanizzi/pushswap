/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:03 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/05 11:29:26 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(int *stack)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (stack[i] && stack[i + 1])
	{
		temp = stack[i];
		stack[i] = stack[i + 1];
		stack[i + 1] = temp;
	}
}

void	sb(int *stack)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (stack[i] && stack[i + 1])
	{
		temp = stack[i];
		stack[i] = stack[i + 1];
		stack[i + 1] = temp;
	}
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
