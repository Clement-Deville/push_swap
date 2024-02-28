/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:59:14 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 18:24:30 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

// void	sort_three(t_stack *a)
// {
// 	if (is_sorted(a))
// 		return ;
// 	if (actual_value(a->begin) > next_value(a->begin))
// 	{
// 		if (actual_value(a->begin) < prev_value(a->begin))
// 			do_swap(a, "sa");
// 		else
// 		{
// 			if (prev_value(a->begin) < next_value(a->begin))
// 			{
// 				do_swap(a, "sa");
// 				do_reverse_rotate(a, 1, "rra");
// 			}
// 			else
// 				do_rotate(a, 1, "ra");
// 		}
// 	}
// 	else
// 	{
// 		if (actual_value(a->begin) < prev_value(a->begin))
// 		{
// 			do_swap(a, "sa");
// 			do_rotate(a, 1, "ra");
// 		}
// 		else
// 			do_reverse_rotate(a, 1, "rra");
// 	}
// }

void	sort_three(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (actual_value(a->begin) > next_value(a->begin)
		&& actual_value(a->begin) < prev_value(a->begin))
		do_swap(a, "sa");
	else if (actual_value(a->begin) > next_value(a->begin)
		&& prev_value(a->begin) < next_value(a->begin))
	{
		do_swap(a, "sa");
		do_reverse_rotate(a, 1, "rra");
	}
	else if (actual_value(a->begin) > next_value(a->begin)
		&& prev_value(a->begin) > next_value(a->begin))
		do_rotate(a, 1, "ra");
	else if (actual_value(a->begin) < next_value(a->begin)
		&& actual_value(a->begin) < prev_value(a->begin))
	{
		do_swap(a, "sa");
		do_rotate(a, 1, "ra");
	}
	else if (actual_value(a->begin) < next_value(a->begin)
		&& actual_value(a->begin) > prev_value(a->begin))
		do_reverse_rotate(a, 1, "rra");
}
