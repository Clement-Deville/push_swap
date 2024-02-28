/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:41:23 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 10:10:36 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	do_move_back(t_stack *a, t_stack *b, t_move_bt *move)
{
	do_rr(a, b, move->rr);
	do_rrr(a, b, move->rrr);
	do_rotate(a, move->ra);
	do_reverse_rotate(a, move->rra);
	do_rotate(b, move->rb);
	do_reverse_rotate(b, move->rrb);
	push(b, a);
}

void	put_small_on_top(t_stack *a)
{
	t_dblist	*actual;
	int			small;
	int			index_small;
	int			index;

	index = 0;
	index_small = 0;
	small = *(int *)a->begin->content;
	actual = a->begin;
	while (actual->next != a->begin)
	{
		index++;
		actual = actual->next;
		if (small > actual_value(actual))
		{
			small = actual_value(actual);
			index_small = index;
		}
	}
	if (index_small < a->size - index_small)
	{
		do_rotate(a, index_small);
		print_move(index_small, "ra");
	}
	else
	{
		do_reverse_rotate(a, a->size - index_small);
		print_move(a->size - index_small, "rra");
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	t_move_bt	move;
	int			target;

	if (a->size == 2)
	{
		rotate(a);
		print_move(1, "ra");
	}
	else if (a->size == 3)
		sort_three(a);
	else
	{
		while (a->size > 3)
		{
			push(a, b);
			print_move(1, "pb");
		}
		if (is_sorted(a) == FALSE)
			sort_three(a);
		while (b->size > 0)
		{
			init_move(&move);
			target = target_a(*(int *)b->begin->content, a);
			move = get_best_move(a, b, target, 0);
			do_move_back(a, b, &move);
			print_full(move);
			print_move(1, "pa");
		}
	}
	put_small_on_top(a);
}
