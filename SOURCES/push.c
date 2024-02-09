/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:12:13 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:37 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static t_bool	isalone(t_dblist *begin)
{
	if (begin == NULL)
		return (FALSE);
	if (begin->next == begin)
		return (TRUE);
	else
		return (FALSE);
}

int	push(t_stack *src, t_stack *dest)
{
	t_dblist	*temp;

	temp = src->begin;
	if (src->begin == NULL)
		return (0);
	if (isalone(src->begin))
	{
		src->begin = NULL;
	}
	else
	{
		src->begin->prev->next = src->begin->next;
		src->begin->next->prev = src->begin->prev;
		src->begin = src->begin->next;
	}
	if (dest->begin == NULL)
	{
		dest->begin = temp;
		dest->begin->next = dest->begin;
		dest->begin->prev = dest->begin;
	}
	else
		ft_dblstadd_before(dest->begin, temp);
	src->size--;
	dest->size++;
	return (0);
}
