/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 14:36:13 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static t_bool	is_empty(t_move_bt *solution)
{
	if (solution->count == 0)
		return (TRUE);
	else
		return (FALSE);
}

static void	keep_best_between(t_move_bt *solution, t_move_bt move)
{
	if (solution->count > move.count || is_empty(solution))
		*solution = move;
}

t_move_bt	get_best(t_stack *a, t_stack *b, t_move_bt *best)
{
	int			index_a;
	int			index_b;
	t_dblist	*actual;
	t_move_bt	move;

	init_move(&move);
	index_a = 0;
	actual = a->begin;
	while (index_a < a->size)
	{
		index_b = target_b(*(int *)(actual->content), b);
		move = get_best_move(a, b, index_a, index_b);
		keep_best_between(best, move);
		actual = actual->next;
		index_a++;
		if (actual == a->begin)
			break ;
	}
	return (*best);
}

void	solve_big(t_stack *a, t_stack *b)
{
	t_move_bt	best;
	int			i;
	int			size;

	i = 0;
	do_push(a, b, 2, "pb");
	size = a->size;
	init_move(&best);
	while (i < size - 3)
	{
		best = get_best(a, b, &best);
		do_move(a, b, &best);
		i++;
	}
	sort_three(a);
	push_back(a, b);
}
