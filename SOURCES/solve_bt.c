/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/14 14:53:46 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	init_move(t_move_bt **move)
{
	int	i;

	i = 0;
	while (i < DEEPNESS)
	{
		move[i]->count = 0;
		move[i]->ra = 0;
		move[i]->rra = 0;
		move[i]->rb = 0;
		move[i]->rrb = 0;
		move[i]->rr = 0;
		move[i]->rrr = 0;
		i++;
	}
}

static t_move_bt	*best_of(t_move_bt *best, t_move_bt *actual)
{
	int	i;
	int	count_best;
	int	count_actual;

	i = 0;
	count_best = 0;
	count_actual = 0;
	while (i < DEEPNESS)
	{
		count_best += best->count;
		count_actual += actual->count;
		i++;
	}
	if (count_best <= count_actual)
		return (best);
	else
		return (actual);
}

static void	init_index(int *index)
{
	int	i;

	i = 0;
	while (i < DEEPNESS)
	{
		index[i] = 0;
		i++;
	}
}

int	target_b(t_stack *a, t_stack *b, int index_a)
{
	t_dblist	actual;
	int			index;

	index = 0;
	if(a->size / 2 > index_a)
	{
		while (index != index_a)
		{

		}
	}
	else
	{

	}
}

static void	put_best_in(t_move_bt *solution, t_move_bt *best)
{

}

t_move_bt	*get_best(t_stack *a, t_stack *b, int index, t_move_bt *actual, t_move_bt **best)
{
	int			i;
	int			j;

	i = 0;
	while (i < a->size - 1)
	{
		j = target_b(a, b, i);
		actual[index] = get_best_move(a, b, i, j);
		do_move(a, b, actual[index]);
		if (index == DEEPNESS - 1)
		{
			*best = best_of(*best, actual);
		}
		else
		{
			get_best(a, b, index + 1, actual, best);
		}
		undo_move(a, b, actual[index]);
		i++;
	}
	return (*best);
}

t_move_bt	*solve_bt(t_stack *a, t_stack *b)
{
	t_move_bt	*solution;
	int			i;
	int			size;
	t_move_bt	actual[DEEPNESS];
	t_move_bt	best[DEEPNESS];

	i = 0;
	size = a->size;
	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	// actual and best

	int j;

	j = 0;
	while (j < DEEPNESS - 1)
	{
		init_move(&actual[j]);
		init_move(&best[j]);
		j++;
	}

	// end
	while (i < size)
	{
		put_best_in(&solution[i], get_best(a, b, 0, actual, &best));
		do_move(a, b, *solution);
		solution++;
		i++;
	}
	return (solution - i);
}
