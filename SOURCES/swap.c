/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:13:58 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 14:33:35 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	swap(t_stack *stack)
{
	t_dblist	*temp;

	temp = stack->begin->next;
	stack->begin->next->next->prev = stack->begin;
	stack->begin->next = stack->begin->next->next;
	temp->prev = stack->begin->prev;
	temp->next = stack->begin;
	stack->begin->prev->next = temp;
	stack->begin->prev = temp;
	stack->begin = temp;
}
