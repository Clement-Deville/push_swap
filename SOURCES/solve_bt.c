/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/16 19:17:48 by cdeville         ###   ########.fr       */
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

int	target_b(int value, t_stack *b)
{
	int			i;
	t_dblist	*actual;

	if (b->begin == NULL)
		return (-1);
	i = 0;
	actual = b->begin;
	if (actual->content > value)
	{
		while (actual->content > value)
		{
			actual = actual->next;
			i++;
		}
	}
	else
	{
		if (actual->prev->content < value)
		{
			i = b->size - 1;
			actual = actual->prev;
		}
		while (actual->prev->content < value)
		{
			actual = actual->prev;
			i--;
		}
	}
	return (i);
}

t_move_bt	*get_best(t_stack *a, t_stack *b, int index, t_move_bt *actual, t_move_bt **solution)
{
	int			i;
	int			j;
	t_dblist	*element;

	i = 0;
	element = a->begin;
	while (i < a->size - 1)
	{
		j = target_b(*(int *)(element->content), b);
		*actual = get_best_move(a, b, i, j);
		do_move(a, b, *actual);
		if (index == DEEPNESS - 1)
		{
			solution[index] = best_of(solution[index],
					(actual - sizeof(t_move_bt) * (DEEPNESS - 1)));
		}
		else
		{
			get_best(a, b, index + 1, actual + sizeof(t_move_bt), solution);
		}
		undo_move(a, b, *actual);
		element = element->next;
		i++;
		if (element->next == a->begin)
			break ;
	}
	return (solution);
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
		get_best(a, b, i, actual, solution);
		apply_it();
		i += DEEPNESS;
	}
	return (solution);
}
