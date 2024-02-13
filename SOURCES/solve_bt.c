/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:41:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/13 16:40:41 by cdeville         ###   ########.fr       */
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

static void	put_best_in(t_move_bt *solution, t_move_bt *best)
{

}

// t_move_bt	*get_best(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	while (/* condition */)
// 	{
// 		/* code */
// 	}


// }

t_move_bt	*solve_bt(t_stack *a, t_stack *b)
{
	t_move_bt	*solution;
	int			i;
	int			size;

	i = 0;
	size = a->size;
	solution = (t_move_bt *)ft_calloc((a->size + 1), sizeof(t_move_bt));
	if (solution == NULL)
		return (NULL);
	while (i < size)
	{
		put_best_in(&solution[i], get_best(a, b));
		do_move(a, b, *solution);
		solution++;
		i++;
	}
	return (solution - i);
}
