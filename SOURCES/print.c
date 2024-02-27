/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 14:17:33 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	print_move(int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%s\n", key);
		i++;
	}
}

void	print_solution(t_move_bt *solution)
{
	int	i;
	int	j;
	int	total;

	total = 0;
	i = 0;
	while (solution->count != -1)
	{
		j = 0;
		// ft_printf("\e[0;33m\n => Step %d\n\n\e[0m", i);
		print_move(solution->rr, "rr");
		print_move(solution->rrr, "rrr");
		print_move(solution->ra, "ra");
		print_move(solution->rra, "rra");
		print_move(solution->rb, "rb");
		print_move(solution->rrb, "rrb");
		print_move(1, "pb");
		// if ((i + 1) % DEEPNESS == 0)
		// 	ft_printf("\e[0;33m");
		// else
		// 	ft_printf("\e[0m");
		// ft_printf("\n%d ", solution->count);
		// while (j < solution->count)
		// {
		// 	ft_printf("+");
		// 	j++;
		// }
		// total += solution->count;
		solution++;
		i++;
	}
	// ft_printf("TOTAL = %d\n", total);
}

void	print_stack(t_dblist *begin)
{
	t_dblist	*actual;
	int			*sd;
	int			i;
	// int			color;

	actual = begin;
	while (actual)
	{
		i = 0;
		sd = actual->content;
		// while (i < *(int *)(actual->content))
		// {
		// 	// color = get_color(*(int *)(actual->content));
		// 	// ft_printf("\e[%im \e[0m|", color);
		// 	ft_printf("\e[48;5;%im \e[0m|", *(int *)(actual->content) % 215 + 16);
		// 	i++;
		// }
		ft_printf("%d\n", *(int *)(actual->content));
		actual = actual->next;
		if (actual == begin)
			break ;
	}
	return ;
}


//utils

void	print_full(t_move_bt move)
{
	// ft_printf("\nCount is: %d\n\n", move.count);
	print_move(move.rr, "rr");
	print_move(move.rrr, "rrr");
	print_move(move.ra, "ra");
	print_move(move.rra, "rra");
	print_move(move.rb, "rb");
	print_move(move.rrb, "rrb");
	// print_move(1, "pb");
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
