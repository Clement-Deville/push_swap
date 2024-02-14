/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:36:49 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:19 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	do_rr(t_stack *a, t_stack *b, int count)
{
	while (count)
	{
		if (a->begin && a->size)
			a->begin = rotate(a->begin);
		if (b->begin && b->size)
			b->begin = rotate(b->begin);
		count--;
	}
}

void	do_rrr(t_stack *a, t_stack *b, int count)
{
	while (count)
	{
		a->begin = reverse_rotate(a->begin);
		b->begin = reverse_rotate(b->begin);
		count--;
	}
}

void	do_rotate(t_stack *stack, int count)
{
	while (count)
	{
		stack->begin = rotate(stack->begin);
		count--;
	}
}

void	do_reverse_rotate(t_stack *stack, int count)
{
	while (count)
	{
		stack->begin = rotate(stack->begin);
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

void	undo_move(t_stack *a, t_stack *b, t_move_bt *move)
{
	push(b, a);
	do_rotate(a, move->rra);
	do_reverse_rotate(a, move->ra);
	do_rotate(b, move->rrb);
	do_reverse_rotate(b, move->rb);
	do_rr(a, b, move->rrr);
	do_rrr(a, b, move->rr);
}
