/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:54:07 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 19:24:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

// t_dblist	*create_first(char *number)
// {

// }

t_dblist	*create_stack(int argc, char *argv[])
{
	int			i;
	int			j;
	int			*number;
	t_dblist	*first;
	t_dblist	*actual;
	char		**split_args;

	i = 1;
	first = NULL;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			number = ft_atoi_edited(split_args[j]);
			if (!number)
			{
				exit_program(first);
			}
			if (!first)
			{
				first = ft_dblstfirst(number);
				actual = first;
			}
			else
				actual = ft_dblstadd_after(actual, ft_dblstnew(number));
			if (!actual)
			{
				error();
				exit_program(first);
			}
			j++;
		}
		i++;
	}
	return (first);
}
