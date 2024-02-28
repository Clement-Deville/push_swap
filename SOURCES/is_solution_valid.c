/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solution_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:47 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 11:34:28 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	apply(char *move, t_stack *a, t_stack *b)
{
	if (ft_strncmp(move, "pa\n", 4) == 0)
		return (check_pa(a, b));
	if (ft_strncmp(move, "pb\n", 4) == 0)
		return (check_pb(a, b));
	if (ft_strncmp(move, "ra\n", 4) == 0)
		return (check_ra(a));
	if (ft_strncmp(move, "rra\n", 5) == 0)
		return (check_rra(a));
	if (ft_strncmp(move, "sa\n", 4) == 0)
		return (check_sa(a));
	if (ft_strncmp(move, "rb\n", 4) == 0)
		return (check_rb(b));
	if (ft_strncmp(move, "rrb\n", 5) == 0)
		return (check_rrb(b));
	if (ft_strncmp(move, "sb\n", 4) == 0)
		return (check_sb(b));
	if (ft_strncmp(move, "rr\n", 4) == 0)
		return (check_rr(a, b));
	if (ft_strncmp(move, "rrr\n", 5) == 0)
		return (check_rrr(a, b));
	else
		return (1);
}

t_bool	is_solution_valid(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (apply(move, a, b))
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
