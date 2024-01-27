/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/27 16:44:34 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	print_stack(t_dblist *begin)
{
	t_dblist	*actual;
	int			*sd;

	actual = begin;
	while (actual)
	{
		sd = actual->content;
		ft_printf("=====%d\n", *(int *)(actual->content));
		actual = actual->next;
		if (actual == begin)
			break ;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_dblist	*begin;

	if (argc < 2)
		return (error());
	begin = create_stack(argc, argv);
	if (!begin)
		return (error());
	// Testing create stack by displaying it
	print_stack(begin);
	exit_program(&begin);
	return (0);
}
