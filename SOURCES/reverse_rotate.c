/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:08:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/17 15:50:20 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	stack->begin = stack->begin->next;
}
