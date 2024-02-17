/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/17 18:42:10 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	init_move(t_move_bt *move)
{
	move->count = 0;
	move->ra = 0;
	move->rra = 0;
	move->rb = 0;
	move->rrb = 0;
	move->rr = 0;
	move->rrr = 0;
}

static t_bool	is_empty(t_move_bt *solution)
{
	if (solution->count == 0)
		return (TRUE);
	else
		return (FALSE);
}

static void	keep_best_between(t_move_bt *solution, t_move_bt *actual)
{
	int	i;
	int	j;
	int	count_solution;
	int	count_actual;

	i = 0;
	count_solution = 0;
	count_actual = 0;
	while (i < DEEPNESS)
	{
		count_solution += solution[i].count;
		count_actual += actual[i].count;
		i++;
		if (solution[i].count == END_FLAG)
			break ;
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

int	target_b(int value, t_stack *b)
{
	int			i;
	t_dblist	*actual;
	int			min;
	int			min_index;
	int			max;
	int			max_index;

	if (b->begin == NULL)
		return (-1);
	if (b->size == 1)
		return (0);
	i = 0;
	actual = b->begin;
	if (*(int *)actual->content > value)
	{
		min = *(int *)actual->content;
		min_index = i;
		while (*(int *)actual->content > value)
		{
			if (*(int *)actual->content < min)
			{
				min = *(int *)actual->content;
				min_index = i;
			}
			actual = actual->next;
			i++;
			if (actual == b->begin)
				break ;
		}
	}
	else
	{
		max = *(int *)actual->content;
		max_index = i;
		if (*(int *)actual->prev->content < value)
		{
			i = b->size - 1;
			actual = actual->prev;
		}
		while (*(int *)actual->prev->content < value)
		{
			if (*(int *)actual->content > max)
			{
				max = *(int *)actual->content;
				max_index = i;
			}
			actual = actual->prev;
			i--;
			if (actual == b->begin)
				break ;
		}
	}
	return (i);
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
		// ft_printf("Before move is done:\n");
		// print_stack(a->begin);
		do_move(a, b, actual);
		// ft_printf("After move is done:\n");
		// print_stack(a->begin);
		if (index == DEEPNESS - 1)
		{
			keep_best_between(&solution[index], actual - (DEEPNESS - 1));
		}
		else
		{
			get_best(a, b, index + 1, actual + 1, solution);
		}
		undo_move(a, b, actual);
		// ft_printf("After move is undone:\n");
		// print_stack(a->begin);
		current = current->next;
		index_a++;
		if (current->next == a->begin)
			break ;
	}
	return (solution);
}

void	init_solve(void *actual)
{
	int	i;

	i = 0;
	actual = (t_move_bt **)actual;
	while (i < DEEPNESS)
	{
		init_move(&actual[i]);
		i++;
	}
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
	size = a->size;
	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	solution[a->size + 1].count = END_FLAG;
	init_solve(&actual);
	while (i < size)
	{
		get_best(a, b, 0, actual, &solution[i]);
		apply_it(a, b, &solution[i]);
		i += DEEPNESS;
	}
	return (solution);
}
