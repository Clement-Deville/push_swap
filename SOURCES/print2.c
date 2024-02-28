/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:33:53 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 10:34:19 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	print_full(t_move_bt move)
{
	print_move(move.rr, "rr");
	print_move(move.rrr, "rrr");
	print_move(move.ra, "ra");
	print_move(move.rra, "rra");
	print_move(move.rb, "rb");
	print_move(move.rrb, "rrb");
}

void	print_before(t_move_bt *solution, t_move_bt *actual, int index)
{
	int	i;

	i = 0;
	ft_printf("\e[0;33m\nBEFORE !\n\n");
	while (i < index + 1)
	{
		if (solution[i].count == END_FLAG)
			break ;
		ft_printf("\nDEEPNESS = %d\n\n", i);
		ft_printf("SOLUTION:  \n");
		print_full(solution[i]);
		ft_printf("\nACTUAL:  \n");
		print_full(actual[i]);
		i++;
	}
}

void	print_after(t_move_bt *solution, int index)
{
	int	i;

	i = 0;
	ft_printf("\e[0;31m\nAFTER !\n\n");
	while (i < index + 1)
	{
		if (solution[i].count == END_FLAG)
			break ;
		ft_printf("\nDEEPNESS = %d\n\n", i);
		ft_printf("SOLUTION:  \n");
		print_full(solution[i]);
		i++;
	}
}
