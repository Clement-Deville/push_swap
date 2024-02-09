/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:59:39 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/09 13:28:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	del_content(int *number)
{
	free(number);
	number = NULL;
}

int	exit_program(t_dblist **begin)
{
	if (*begin)
		(*begin)->prev->next = NULL;
	ft_free("%d", begin, &del_content);
	return (0);
	// exit (0);
}
