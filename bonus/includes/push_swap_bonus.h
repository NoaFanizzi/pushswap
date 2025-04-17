/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:27:51 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/14 10:18:02 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_size
{
	int				a;
	int				b;
}					t_size;

typedef struct s_stack
{
	int				*a;
	int				*b;
	int				*index_a;
	int				*index_b;
	struct s_size	size;
}					t_stack;

typedef struct s_copy
{
	int				*array;
	int				size;
}					t_copy;

int					ft_get_index(t_stack *stack);
int					ft_parse(char **stack, int argc);
void				pa(int *stack_a, int *stack_b, t_size size);
void				pb(int *stack_a, int *stack_b, t_size size);
void				ft_reorder(int *stack, int size);
void				load_stack(int *stack_a, char **argv);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
void				sa(int *stack);
void				sb(int *stack);
void				ss(int *stack_a, int *stack_b);
int					ft_get_stack(t_stack *stack, int argc, char **argv);

#endif