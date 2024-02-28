/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 10:34:06 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	print_move(int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%s\n", key);
		i++;
	}
}

void	print_solution(t_move_bt *solution)
{
	int	i;
	int	j;
	int	total;

	total = 0;
	i = 0;
	while (solution->count != -1)
	{
		j = 0;
		print_move(solution->rr, "rr");
		print_move(solution->rrr, "rrr");
		print_move(solution->ra, "ra");
		print_move(solution->rra, "rra");
		print_move(solution->rb, "rb");
		print_move(solution->rrb, "rrb");
		print_move(1, "pb");
		solution++;
		i++;
	}
}

void	print_stack(t_dblist *begin)
{
	t_dblist	*actual;
	int			i;

	actual = begin;
	while (actual)
	{
		i = 0;
		ft_printf("%d\n", *(int *)(actual->content));
		actual = actual->next;
		if (actual == begin)
			break ;
	}
	return ;
}
