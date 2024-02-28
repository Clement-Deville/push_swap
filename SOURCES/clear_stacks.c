/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:57:04 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 19:57:12 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	clear_stacks(t_stack *a, t_stack *b)
{
	if (a->begin)
		a->begin->prev->next = NULL;
	if (b->begin)
		b->begin->prev->next = NULL;
	ft_free("%d", &a->begin, &del_content);
	ft_free("%d", &b->begin, &del_content);
}
