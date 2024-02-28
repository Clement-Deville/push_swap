/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:45:33 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 18:48:01 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	target_b_value_is_bigger(int value, t_stack *stack)
{
	int			i;
	t_dblist	*actual;

	i = 0;
	actual = stack->begin;
	if (value_is_bigger(value, actual))
	{
		if (actual_value(actual) > prev_value(actual))
			return (0);
		if (value_is_smaller(value, actual->prev))
			return (0);
		i = stack->size - 1;
		actual = actual->prev;
	}
	while (value_is_bigger(value, actual->prev))
	{
		if (prev_value(actual) < actual_value(actual))
			break ;
		if (actual == stack->begin)
			break ;
		actual = actual->prev;
		i--;
	}
	return (i);
}

int	target_b_value_is_smaller(int value, t_stack *stack)
{
	int			i;
	t_dblist	*actual;

	i = 0;
	actual = stack->begin;
	if (prev_value(actual) < actual_value(actual)
		&& value_is_smaller(value, actual->prev))
		return (0);
	while (value_is_smaller(value, actual))
	{
		actual = actual->next;
		i++;
		if (prev_value(actual) < actual_value(actual))
			break ;
		if (actual == stack->begin)
			break ;
	}
	return (i);
}

int	target_b(int value, t_stack *stack)
{
	if (value_is_smaller(value, stack->begin))
		return (target_b_value_is_smaller(value, stack));
	else
		return (target_b_value_is_bigger(value, stack));
}
