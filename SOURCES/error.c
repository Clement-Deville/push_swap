/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:28:03 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 10:11:52 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	error_check(void)
{
	char	*str;

	str = get_next_line(0);
	if (ft_strncmp(str, "Error\n", 7) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	while (str)
	{
		free(str);
		str = get_next_line(0);
	}
	return (0);
}
