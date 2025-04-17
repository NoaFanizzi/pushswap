/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:11:21 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/10 17:35:17 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_stack(int *stack_a, char **argv)
{
	size_t	i;
	size_t	j;
	int		converted;

	i = 0;
	j = 1;
	while (argv[j])
	{
		converted = ft_atoi(argv[j]);
		stack_a[i] = converted;
		i++;
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ft_push_swap(argv, argc);
}
