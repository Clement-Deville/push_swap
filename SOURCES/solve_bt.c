/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 12:24:29 by cdeville         ###   ########.fr       */
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

static void	keep_best_between(t_move_bt *solution, t_move_bt *actual, int index)
{
	int	i;
	int	j;
	int	count_solution;
	int	count_actual;

	i = 0;
	count_solution = 0;
	count_actual = 0;
	while (i < index + 1)
	{
		if (solution[i].count == END_FLAG)
			break ;
		count_solution += solution[i].count;
		count_actual += actual[i].count;
		i++;
	}
	if (count_solution > count_actual || is_empty(solution))
	{
		j = 0;
		while (j < i)
		{
			solution[j] = actual[j];
			j++;
		}
	}
}

t_move_bt	*get_best(t_stack *a, t_stack *b, int index, t_move_bt *actual, t_move_bt *solution)
{
	int			index_a;
	int			index_b;
	t_dblist	*current;

	index_a = 0;
	current = a->begin;
	while (index_a < a->size)
	{
		index_b = target_b(*(int *)(current->content), b);
		*actual = get_best_move(a, b, index_a, index_b);
		if (index == DEEPNESS - 1 || a->size == 1)
			keep_best_between(solution, actual - index, index);
		else
		{
			do_move(a, b, actual);
			get_best(a, b, index + 1, actual + 1, solution);
			undo_move(a, b, actual);
		}
		current = current->next;
		index_a++;
		if (current == a->begin)
			break ;
	}
	return (solution);
}

void	apply_it(t_stack *a, t_stack *b, t_move_bt *solution)
{
	int	i;

	i = 0;
	while (i < DEEPNESS && a->size > 0)
	{
		do_move(a, b, &solution[i]);
		i++;
	}
}

t_move_bt	*solve_bt(t_stack *a, t_stack *b)
{
	t_move_bt	*solution;
	int			i;
	int			size;
	t_move_bt	actual[DEEPNESS];

	i = 0;
	push(a, b);
	print_move(1, "pb");
	push(a, b);
	print_move(1, "pb");
	size = a->size;
	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	solution[a->size].count = END_FLAG;
	init_solve(&actual);
	while (i < size)
	{
		get_best(a, b, 0, actual, &solution[i]);
		apply_it(a, b, &solution[i]);
		i += DEEPNESS;
	}
	return (solution);
}
