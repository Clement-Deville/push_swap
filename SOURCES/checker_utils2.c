/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:35:01 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 14:29:54 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	check_rb(t_stack *b)
{
	if (b->size == 0)
		return (1);
	rotate(b);
	return (0);
}

int	check_rrb(t_stack *b)
{
	if (b->size == 0)
		return (1);
	reverse_rotate(b);
	return (0);
}

int	check_sb(t_stack *b)
{
	if (b->size == 0)
		return (1);
	swap(b);
	return (0);
}

int	check_rr(t_stack *a, t_stack *b)
{
	if (a->size == 0 || b->size == 0)
		return (1);
	rotate(a);
	rotate(b);
	return (0);
}

int	check_rrr(t_stack *a, t_stack *b)
{
	if (a->size == 0 || b->size == 0)
		return (1);
	reverse_rotate(a);
	reverse_rotate(b);
	return (0);
}
