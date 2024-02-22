/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:32:15 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/22 14:06:02 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

// static	int	prev_value(t_dblist *actual)
// {
// 	return (*(int *)actual->prev->content);
// }

// static	int	next_value(t_dblist *actual)
// {
// 	return (*(int *)actual->next->content);
// }

static	int	actual_value(t_dblist *actual)
{
	return (*(int *)actual->content);
}

int	get_bigest(t_stack *b)
{
	t_dblist	*actual;
	int			i;
	int			index_bigest;
	int			biggest;

	i = 0;
	actual = b->begin;
	index_bigest = 0;
	biggest = actual_value(actual);
	while (1)
	{
		if (actual_value(actual) > biggest)
		{
			index_bigest = i;
			biggest = actual_value(actual);
		}
		actual = actual->next;
		i++;
		if (actual == b->begin)
			break ;
	}
	return (index_bigest);
}

void	push_back(t_stack *a, t_stack *b)
{
	int			index_bigest;
	t_move_bt	bigest_on_top;

	init_move(&bigest_on_top);
	index_bigest = get_bigest(b);
	if (index_bigest < b->size - index_bigest + 1)
	{
		bigest_on_top.rb = index_bigest;
		bigest_on_top.count = index_bigest;
		print_move(bigest_on_top.rb, "rb");
	}
	else
	{
		bigest_on_top.rrb = b->size - index_bigest;
		bigest_on_top.count = b->size - index_bigest;
		print_move(bigest_on_top.rrb, "rrb");
	}
	do_move(a, b, &bigest_on_top);
	while (b->size >= 1)
	{
		push(b, a);
		print_move(1, "pa");
	}
}
