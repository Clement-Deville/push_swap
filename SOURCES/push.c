/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:12:13 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/05 15:39:29 by cdeville         ###   ########.fr       */
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

int	push(t_dblist **begin_src, t_dblist **begin_dest)
{
	if (*begin_src == NULL)
		return (0);
	if (*begin_dest == NULL)
	{
		*begin_dest = ft_dblstfirst((*begin_src)->content);
		if (*begin_dest == NULL)
			return (-1);
	}
	ft_dblstadd_before(*begin_dest, *begin_src);
	if (isalone(*begin_src))
		*begin_src = NULL;
	else
		*begin_src = (*begin_src)->next;
	return (0);
}
