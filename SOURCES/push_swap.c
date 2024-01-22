/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 17:54:18 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	print_stack(t_dblist *first)
{
	t_dblist	*actual;

	actual = first;
	while (actual)
	{
		int *sd;
		sd = actual->content;
		printf("=====%d\n", *(int *)(actual->content));
		actual = actual->next;
		if (actual == first)
			break ;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_dblist	*first;

	if (argc < 2)
		return (error());
	first = create_stack(argc, argv);
	if (!first)
		return (error());
	// Testing create stack by displaying it
	print_stack(first);
	exit_program(first);
	return (0);
}
