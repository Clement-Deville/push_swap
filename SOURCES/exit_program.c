/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:59:39 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 18:05:45 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	del_content(t_dblist *node)
{
	free(node->content);
	node->content = NULL;
}

int	exit_program(t_dblist *first)
{
	t_dblist	*actual;
	t_dblist	*next;

	if (!first)
		exit (1);
	actual = first->next;
	while (actual != first)
	{
		next = actual->next;
		del_content(actual);
		free(actual);
		actual = next;
	}
	del_content(first);
	free(first);
	exit (1);
}
