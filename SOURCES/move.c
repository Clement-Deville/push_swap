/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:36:49 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 10:42:49 by cdeville         ###   ########.fr       */
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
