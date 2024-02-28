/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:59:39 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 18:01:11 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	del_content(int *number)
{
	free(number);
	number = NULL;
}

int	exit_program(t_dblist **begin_a, t_dblist **begin_b)
{
	if (*begin_a)
		(*begin_a)->prev->next = NULL;
	ft_free("%d", begin_a, &del_content);
	if (*begin_b)
		(*begin_b)->prev->next = NULL;
	ft_free("%d", begin_b, &del_content);
	exit (0);
}
