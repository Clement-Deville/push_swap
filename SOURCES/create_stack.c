/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:54:07 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/29 14:25:42 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

t_dblist	*create_stack(char *split_args[])
{
	int			j;
	int			*number;
	t_dblist	*begin;
	t_dblist	*actual;

	begin = NULL;
	j = 0;
	while (split_args[j])
	{
		number = ft_atoi_edited(split_args[j]);
		if (!number)
		{
			ft_free("%s", split_args);
			if (begin)
				(begin)->prev->next = NULL;
			ft_free("%d", &begin, &del_content);
			return (NULL);
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
			ft_free("%s", split_args);
			exit_program(&begin, NULL);
		}
		j++;
	}
	ft_free("%s", split_args);
	return (begin);
}


// t_dblist	*add_number(char *arg, t_dblist **begin)
// {
// 	int			*number;

// 	number = ft_atoi_edited(arg);
// 	if (!number)
// 	{
// 		clear_stacks(begin, NULL);
// 		return (NULL);
// 	}
// 	if (!begin)
// 		begin = ft_dblstfirst(number);
// 	else
// 		ft_dblstadd_before(begin, ft_dblstnew(number));
// 	if (!begin->prev)
// 	{
// 		ft_free("%s", split_args);
// 		exit_program(&begin, NULL);
// 	}
// }

// t_dblist	*create_stack(char *split_args[])
// {
// 	int			j;
// 	int			*number;
// 	t_dblist	*begin;

// 	begin = NULL;
// 	j = 0;
// 	while (split_args[j])
// 	{
// 		number = ft_atoi_edited(split_args[j]);
// 		if (!number)
// 		{
// 			ft_free("%s", split_args);
// 			clear_stacks(&begin, NULL);
// 			return (NULL);
// 		}
// 		if (!begin)
// 			begin = ft_dblstfirst(number);
// 		else
// 			ft_dblstadd_before(begin, ft_dblstnew(number));
// 		if (!begin->prev)
// 		{
// 			ft_free("%s", split_args);
// 			exit_program(&begin, NULL);
// 		}
// 		j++;
// 	}
// 	ft_free("%s", split_args);
// 	return (begin);
// }
