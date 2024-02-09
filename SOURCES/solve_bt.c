/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/09 17:01:30 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static void	init(t_move_bt *move)
{
	move->count = 0;
	move->ra = 0;
	move->rra = 0;
	move->rb = 0;
	move->rrb = 0;
	move->rr = 0;
	move->rrr = 0;
}

// t_move_bt	get_move()
// {

// }

t_move_bt	get_best(t_stack *a, t_stack *b)
{
	t_move_bt	best;
	(void)a;
	(void)b;
	// t_move_bt	move;
	// t_dblist	*actual;

	init(&best);
	best.ra = 2;
	best.rr = 1;
	// actual = a->begin;
	// while (actual != a->begin)
	// {
	// 	move = get_move(, b->begin);
	// }
	return (best);
}

void	do_rr(t_stack *a, t_stack *b, int count)
{
	while (count)
	{
		if (a->begin && a->size)
			rotate(a->begin);
		if (b->begin && b->size)
			rotate(b->begin);
		count--;
	}
}
void	do_rrr(t_stack *a, t_stack *b, int count)
{
	while (count)
	{
		reverse_rotate(a->begin);
		reverse_rotate(b->begin);
		count--;
	}
}
void	do_rotate(t_stack *stack, int count)
{
	while (count)
	{
		rotate(stack->begin);
		count--;
	}
}
void	do_reverse_rotate(t_stack *stack, int count)
{
	while (count)
	{
		rotate(stack->begin);
		count--;
	}
}

void	do_move(t_stack *a, t_stack *b, t_move_bt move)
{
	do_rr(a, b, move.rr);
	do_rrr(a, b, move.rrr);
	do_rotate(a, move.ra);
	do_reverse_rotate(a, move.rra);
	do_rotate(b, move.rb);
	do_reverse_rotate(b, move.rrb);
	push(a, b);
}

t_move_bt	*solve_bt(t_stack *a, t_stack *b)
{
	t_move_bt	*solution;

	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	while (solution)
	{
		*solution = get_best(a, b);
		do_move(a, b, *solution);
		solution++;
	}
	return (solution);
}
