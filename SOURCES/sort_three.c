/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:59:14 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 11:29:06 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	sort_three(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (actual_value(a->begin) > next_value(a->begin))
	{
		if (actual_value(a->begin) < prev_value(a->begin))
		{
			swap(a);
			print_move(1, "sa");
		}
		else
		{
			if (prev_value(a->begin) < next_value(a->begin))
			{
				swap(a);
				print_move(1, "sa");
				reverse_rotate(a);
				print_move(1, "rra");
			}
			else
			{
				rotate(a);
				print_move(1, "ra");
			}
		}
	}
	else
	{
		if (actual_value(a->begin) < prev_value(a->begin))
		{
			swap(a);
			print_move(1, "sa");
			rotate(a);
			print_move(1, "ra");
		}
		else
		{
			reverse_rotate(a);
			print_move(1, "rra");
		}
	}
}
