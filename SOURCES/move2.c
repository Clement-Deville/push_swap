/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:30:39 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 14:41:27 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	do_push(t_stack *src, t_stack *dest, int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		push(src, dest);
		i++;
	}
	print_move(count, key);
}

void	do_swap(t_stack *stack, char *key)
{
	swap(stack);
	print_move(1, key);
}

void	do_move(t_stack *a, t_stack *b, t_move_bt *move)
{
	do_rr(a, b, move->rr);
	do_rrr(a, b, move->rrr);
	do_rotate(a, move->ra, "ra");
	do_reverse_rotate(a, move->rra, "rra");
	do_rotate(b, move->rb, "rb");
	do_reverse_rotate(b, move->rrb, "rrb");
	push(a, b);
}

// void	undo_move(t_stack *a, t_stack *b, t_move_bt *move)
// {
// 	push(b, a);
// 	do_rotate(a, move->rra);
// 	do_reverse_rotate(a, move->ra);
// 	do_rotate(b, move->rrb);
// 	do_reverse_rotate(b, move->rb);
// 	do_rr(a, b, move->rrr);
// 	do_rrr(a, b, move->rr);
// }
