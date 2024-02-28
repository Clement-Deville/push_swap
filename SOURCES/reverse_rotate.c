/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 14:13:31 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	reverse_rotate(t_stack *stack, char *key)
{
	stack->begin = stack->begin->prev;
	print_move(1, key);
}
