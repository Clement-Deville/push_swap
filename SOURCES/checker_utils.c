/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:24:04 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 11:34:46 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	check_pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return (1);
	push(b, a);
	return (0);
}

int	check_pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return (1);
	push(a, b);
	return (0);
}

int	check_ra(t_stack *a)
{
	if (a->size == 0)
		return (1);
	rotate(a);
	return (0);
}

int	check_rra(t_stack *a)
{
	if (a->size == 0)
		return (1);
	reverse_rotate(a);
	return (0);
}

int	check_sa(t_stack *a)
{
	if (a->size == 0)
		return (1);
	swap(a);
	return (0);
}
