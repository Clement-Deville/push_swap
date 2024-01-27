/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:54:07 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/27 16:45:17 by cdeville         ###   ########.fr       */
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
	t_dblist	*begin;
	t_dblist	*actual;
	char		**split_args;

	i = 1;
	begin = NULL;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			number = ft_atoi_edited(split_args[j]);
			if (!number)
			{
				error();
				ft_free("%s", split_args);
				exit_program(&begin);
			}
			if (!begin)
			{
				begin = ft_dblstfirst(number);
				actual = begin;
			}
			else
				actual = ft_dblstadd_after(actual, ft_dblstnew(number));
			if (!actual)
			{
				error();
				ft_free("%s", split_args);
				exit_program(&begin);
			}
			j++;
		}
		ft_free("%s", split_args);
		i++;
	}
	return (begin);
}