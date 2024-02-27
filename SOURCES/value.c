/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:25:00 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 11:25:44 by cdeville         ###   ########.fr       */
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
