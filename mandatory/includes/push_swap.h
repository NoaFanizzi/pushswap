/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:23:54 by nofanizz          #+#    #+#             */
/*   Updated: 2025/03/14 10:18:19 by nofanizz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_copy
{
	int				*array;
	int				size;
}					t_copy;

typedef struct s_current
{
	int				pos;
	int				diff;
}					t_current;

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

typedef struct s_cheapest
{
	int				cost;
	t_size			pos;
}					t_cheapest;

typedef struct s_infos
{
	int				diff;
	int				cost;
	int				pos;
	int				nb;
	int				a;
}					t_infos;

///////////////////////

// push.c
void				pb(int *stack_a, int *stack_b, t_size size);
void				pa(int *stack_a, int *stack_b, t_size size);

// swap.c
void				sa(int *stack);
void				sb(int *stack);
void				ss(int *stack_a, int *stack_b);
void				ft_push_swap(char **initial_stack, int argc);

// rotate.c
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);

// reversed rotate.c
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);

// movements.c
void				ft_arrange(t_cheapest *cheapest, t_stack *stack);
void				ft_b_b(t_cheapest *cheapest, t_stack *stack);
void				ft_b_l(t_cheapest *cheapest, t_stack *stack);
void				ft_l_l(t_cheapest *cheapest, t_stack *stack);
void				ft_l_b(t_cheapest *cheapest, t_stack *stack);

// parsing.c
int					ft_parse(char **stack, int argc);

// set.c
void				ft_set_top(t_stack *stack);

// sort.c
int					ft_sort(t_stack *stack);

// cost.c
t_cheapest			ft_cheapest_diff_a(t_stack *stack, int i);
t_cheapest			ft_cheapest_diff_b(t_stack *stack, int i);

// find_biggest.c
int					ft_is_new_biggest_a(t_stack *stack, int nb);
int					ft_is_new_biggest_b(t_stack *stack, int nb);
t_cheapest			ft_get_biggest_a(t_stack *stack, int i);
t_cheapest			ft_get_biggest_b(t_stack *stack, int i);

// find_lowest.c
t_cheapest			ft_get_lowest_a(t_stack *stack, int i);
t_cheapest			ft_get_lowest_b(t_stack *stack, int i);
int					ft_is_new_lowest_a(t_stack *stack, int nb);
int					ft_is_new_lowest_b(t_stack *stack, int nb);
int					ft_abs(int num);

//mem_allocation.c
void				ft_free_all(t_stack *stack);
int					ft_index_allocation(t_stack *stack, int argc);
int					ft_stack_allocation(t_stack *stack, int argc);

// index.c
int					ft_get_index(t_stack *stack);

// push_swap.c
void				ft_push_swap(char **args, int argc);
void				load_stack(int *stack_a, char **argv);

// checker.c
int					ft_checker_presence(char **stack);

#endif