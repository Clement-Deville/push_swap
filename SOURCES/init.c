/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:12:22 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 11:13:14 by cdeville         ###   ########.fr       */
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
