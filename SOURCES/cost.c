/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:20:58 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/22 18:07:23 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

// void	print_moves(t_move_bt *solution)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (i == 0)
// 			ft_printf("=== FOR ra_rb ==\n\n");
// 		if (i == 1)
// 			ft_printf("=== FOR ra_rrb ==\n\n");
// 		if (i == 2)
// 			ft_printf("=== FOR rra_rb ==\n\n");
// 		if (i == 3)
// 			ft_printf("=== FOR rra_rrb == \n\n");
// 		print_move(solution->rr, "rr");
// 		print_move(solution->rrr, "rrr");
// 		print_move(solution->ra, "ra");
// 		print_move(solution->rra, "rra");
// 		print_move(solution->rb, "rb");
// 		print_move(solution->rrb, "rrb");
// 		print_move(1, "pa");
// 		solution++;
// 		i++;
// 	}
// }

t_move_bt	best_of(t_move_bt *move)
{
	int	i;
	int	best;

	i = 0;
	best = 0;
	while (i < 4)
	{
		if (move[best].count > move[i].count)
			best = i;
		i++;
	}
	return (move[best]);
}

t_move_bt	get_ra_rb(int index_a, int index_b)
{
	t_move_bt	ra_rb;

	init_move(&ra_rb);
	if (index_a >= index_b)
	{
		ra_rb.count = index_a + 1;
		ra_rb.rr = index_b;
		ra_rb.ra = index_a - index_b;
	}
	else
	{
		ra_rb.count = index_b + 1;
		ra_rb.rr = index_a;
		ra_rb.rb = index_b - index_a;
	}
	return (ra_rb);
}

t_move_bt	get_ra_rrb(t_stack *b, int index_a, int index_b)
{
	t_move_bt	ra_rrb;

	init_move(&ra_rrb);
	ra_rrb.count = index_a + (b->size - 1) - index_b + 2;
	ra_rrb.ra = index_a;
	ra_rrb.rrb = (b->size - 1) - index_b + 1;
	return (ra_rrb);
}

t_move_bt	get_rra_rb(t_stack *a, int index_a, int index_b)
{
	t_move_bt	rra_rb;

	init_move(&rra_rb);
	rra_rb.count = (a->size - 1) - index_a + index_b + 1;
	rra_rb.rra = (a->size - 1) - index_a + 1;
	rra_rb.rb = index_b;
	return (rra_rb);
}

t_move_bt	get_rra_rrb(t_stack *a, t_stack *b, int index_a, int index_b)
{
	t_move_bt	rra_rrb;

	init_move(&rra_rrb);
	if (a->size - index_a <= b->size - index_b)
	{
		rra_rrb.count = (b->size - 1) - index_b + 2;
		rra_rrb.rrr = (a->size - 1) - index_a + 1;
		rra_rrb.rrb = ((b->size - 1) - index_b) - ((a->size - 1) - index_a);
	}
	else
	{
		rra_rrb.count = (a->size - 1) - index_a + 2;
		rra_rrb.rrr = (b->size - 1) - index_b + 1;
		rra_rrb.rra = ((a->size - 1) - index_a) - ((b->size - 1) - index_b);
	}
	return (rra_rrb);
}

t_move_bt	                                                                                                                                                                                                                     get_best_move(t_stack *a, t_stack *b, int index_a, int index_b)
{
	t_move_bt	move[4];

	move[0] = get_ra_rb(index_a, index_b);
	move[1]	= get_ra_rrb(b, index_a, index_b);
	move[2]	= get_rra_rb(a, index_a, index_b);
	move[3]	= get_rra_rrb(a, b, index_a, index_b);
	// print_moves(move);
	return (best_of(move));
}
