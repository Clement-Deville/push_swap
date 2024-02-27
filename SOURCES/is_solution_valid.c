/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solution_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 19:42:31 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	apply(char *move, t_stack *a, t_stack *b)
{
	if (ft_strncmp(move, "pa\n", 4) == 0)
	{
		if (b->size == 0)
			return (1);
		push(b, a);
		return (0);
	}
	if (ft_strncmp(move, "pb\n", 4) == 0)
	{
		if (a->size == 0)
			return (1);
		push(a, b);
		return (0);
	}
	if (ft_strncmp(move, "ra\n", 4) == 0)
	{
		if (a->size == 0)
			return (1);
		rotate(a);
		return (0);
	}
	if (ft_strncmp(move, "rra\n", 5) == 0)
	{
		if (a->size == 0)
			return (1);
		reverse_rotate(a);
		return (0);
	}
	if (ft_strncmp(move, "sa\n", 4) == 0)
	{
		if (a->size == 0)
			return (1);
		swap(a);
		return (0);
	}
	if (ft_strncmp(move, "rb\n", 4) == 0)
	{
		if (b->size == 0)
			return (1);
		rotate(b);
		return (0);
	}
	if (ft_strncmp(move, "rrb\n", 5) == 0)
	{
		if (b->size == 0)
			return (1);
		reverse_rotate(b);
		return (0);
	}
	if (ft_strncmp(move, "sb\n", 4) == 0)
	{
		if (b->size == 0)
			return (1);
		swap(b);
		return (0);
	}
	if (ft_strncmp(move, "rr\n", 4) == 0)
	{
		if (a->size == 0 || b->size == 0)
			return (1);
		do_rr(a, b, 1);
		return (0);
	}
	if (ft_strncmp(move, "rrr\n", 5) == 0)
	{
		if (a->size == 0 || b->size == 0)
			return (1);
		do_rrr(a, b, 1);
		return (0);
	}
	else
		return (1);
}

t_bool	is_solution_valid(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!apply(move, a, b))
		{
			free(move);
			return (FALSE);
		}
		free(move);
		move = get_next_line(0);
	}
	if (is_sorted(a) && b->size == 0)
		return (TRUE);
	else
		return (FALSE);
}
