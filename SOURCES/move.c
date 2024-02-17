/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:36:49 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/17 14:41:50 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	do_rr(t_stack *a, t_stack *b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (a->begin && a->size)
			rotate(a);
		if (b->begin && b->size)
			rotate(b);
		i++;
	}
}

void	do_rrr(t_stack *a, t_stack *b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		i++;
	}
}

void	do_rotate(t_stack *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		rotate(stack);
		i++;
	}
}

void	do_reverse_rotate(t_stack *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		reverse_rotate(stack);
		i++;
	}
}

void	do_move(t_stack *a, t_stack *b, t_move_bt *move)
{
	do_rr(a, b, move->rr);
	do_rrr(a, b, move->rrr);
	do_rotate(a, move->ra);
	do_reverse_rotate(a, move->rra);
	do_rotate(b, move->rb);
	do_reverse_rotate(b, move->rrb);
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
