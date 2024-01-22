/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:41:19 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 17:25:25 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/dblist.h"

t_dblist	*ft_dblstnew(void *content)
{
	t_dblist	*node;

	node = (t_dblist *)malloc(sizeof(t_dblist));
	if (!node)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
