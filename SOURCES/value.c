/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:25:00 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 18:26:39 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	prev_value(t_dblist *actual)
{
	return (*(int *)actual->prev->content);
}

int	next_value(t_dblist *actual)
{
	return (*(int *)actual->next->content);
}

int	actual_value(t_dblist *actual)
{
	return (*(int *)actual->content);
}

t_bool	value_is_bigger(int value, t_dblist *actual)
{
	if (value > *(int *)actual->content)
		return (TRUE);
	return (FALSE);
}

t_bool	value_is_smaller(int value, t_dblist *actual)
{
	if (value < *(int *)actual->content)
		return (TRUE);
	return (FALSE);
}
