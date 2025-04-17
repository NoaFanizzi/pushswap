/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:49 by noa               #+#    #+#             */
/*   Updated: 2025/02/27 17:17:51 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_without(t_copy *src, int nb)
{
	int	i;
	int	j;
	int	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(int) * (src->size - 1));
	if (!cpy)
		return (free(src->array), NULL);
	while (i < src->size)
	{
		if (src->array[i] == nb)
			i++;
		if (i < src->size)
			cpy[j] = src->array[i];
		j++;
		i++;
	}
	free(src->array);
	return (cpy);
}

int	find_smallest(t_copy *cpy)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = cpy->array[i];
	while (i < cpy->size)
	{
		if (cpy->array[i] < smallest)
			smallest = cpy->array[i];
		i++;
	}
	return (smallest);
}

void	ft_array_cpy(t_copy *cpy, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size.a)
	{
		cpy->array[i] = stack->a[i];
		i++;
	}
}

int	ft_get_index(t_stack *stack)
{
	int		i;
	int		j;
	int		smallest;
	t_copy	cpy;

	j = 0;
	cpy.array = malloc(sizeof(int) * (stack->size.a));
	if (!cpy.array)
		return (0);
	cpy.size = stack->size.a;
	ft_array_cpy(&cpy, stack);
	i = -1;
	while (++i < stack->size.a)
	{
		smallest = find_smallest(&cpy);
		while (stack->a[j] != smallest)
			j++;
		stack->index_a[j] = i + 1;
		cpy.array = copy_without(&cpy, smallest);
		if (!(cpy.array))
			return (0);
		cpy.size -= 1;
		j = 0;
	}
	return (free(cpy.array), 1);
}
