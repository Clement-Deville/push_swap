/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/22 18:19:23 by cdeville         ###   ########.fr       */
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

void	print_full(t_move_bt move)
{
	ft_printf("\nCount is: %d\n\n", move.count);
	print_move(move.rr, "rr");
	print_move(move.rrr, "rrr");
	print_move(move.ra, "ra");
	print_move(move.rra, "rra");
	print_move(move.rb, "rb");
	print_move(move.rrb, "rrb");
	print_move(1, "pb");
}

void	print_before(t_move_bt *solution, t_move_bt *actual, int index)
{
	int	i;

	i = 0;
	ft_printf("\e[0;33m\nBEFORE !\n\n");
	while (i < index + 1)
	{
		if (solution[i].count == END_FLAG)
			break ;
		ft_printf("\nDEEPNESS = %d\n\n", i);
		ft_printf("SOLUTION:  \n");
		print_full(solution[i]);
		ft_printf("\nACTUAL:  \n");
		print_full(actual[i]);
		i++;
	}
}

void	print_after(t_move_bt *solution, int index)
{
	int	i;

	i = 0;
	ft_printf("\e[0;31m\nAFTER !\n\n");
	while (i < index + 1)
	{
		if (solution[i].count == END_FLAG)
			break ;
		ft_printf("\nDEEPNESS = %d\n\n", i);
		ft_printf("SOLUTION:  \n");
		print_full(solution[i]);
		i++;
	}
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

	// print_before(solution, actual, index);
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
	// print_after(solution, i - 1);
}

static t_bool	value_is_bigger(int value, t_dblist *actual)
{
	if (value > *(int *)actual->content)
		return (TRUE);
	return (FALSE);
}

static t_bool	value_is_smaller(int value, t_dblist *actual)
{
	if (value < *(int *)actual->content)
		return (TRUE);
	return (FALSE);
}

static	int	prev_value(t_dblist *actual)
{
	return (*(int *)actual->prev->content);
}

// static	int	next_value(t_dblist *actual)
// {
// 	return (*(int *)actual->next->content);
// }

static	int	actual_value(t_dblist *actual)
{
	return (*(int *)actual->content);
}

int	target_b(int value, t_stack *b)
{
	int			i;
	t_dblist	*actual;

	i = 0;
	actual = b->begin;
	if (value_is_smaller(value, actual))
	{
		if (prev_value(actual) < actual_value(actual)
			&& value_is_smaller(value, actual->prev))
			return (0);
		while (value_is_smaller(value, actual))
		{
			actual = actual->next;
			i++;
			if (prev_value(actual) < actual_value(actual))
				break ;
			if (actual == b->begin)
				break ;
		}
	}
	else
	{
		if (value_is_bigger(value, actual))
		{
			if (actual_value(actual) > prev_value(actual))
				return (0);
			if (value_is_smaller(value, actual->prev))
				return (0);
			i = b->size - 1;
			actual = actual->prev;
		}
		while (value_is_bigger(value, actual->prev))
		{
			if (prev_value(actual) < actual_value(actual))
				break ;
			if (actual == b->begin)
				break ;
			actual = actual->prev;
			i--;
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
		// ft_printf("\n\033[0;32m == Move at index_a = %d\n == Target_b is %d = \n == Stack A size is %d = \n\n\033[0m", index_a, index_b, a->size);
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
	print_move(1, "pb");
	size = a->size;
	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	solution[a->size].count = END_FLAG;
	init_solve(&actual);
	while (i < size)
	{
		// ft_printf("\033[0;31m===>Step: %d\n\n\033[0m", i);
		// ft_printf("\n\e[0;35mStack A: \n\n");
		// print_stack(a->begin);
		// ft_printf("\n");
		// ft_printf("Stack B: \n\n");
		// print_stack(b->begin);
		// ft_printf("\n\033[0m");
		get_best(a, b, 0, actual, &solution[i]);
		apply_it(a, b, &solution[i]);
		i += DEEPNESS;
	}
	return (solution);
}
