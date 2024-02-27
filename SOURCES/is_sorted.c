/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:01:06 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 11:36:52 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

t_bool	is_sorted(t_stack *stack)
{
	t_dblist	*actual;

	actual = stack->begin;
	while (actual->next != stack->begin)
	{
		if (actual_value(actual) > next_value(actual))
			return (FALSE);
		actual = actual->next;
	}
	return (TRUE);
}
