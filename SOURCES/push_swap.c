/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 16:20:31 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	start_solving(t_stack *a, t_stack *b)
{
	b->begin = NULL;
	b->size = 0;
	if (is_sorted(a))
		exit_program(&a->begin, &b->begin);
	if (a->size <= 5)
		sort_small(a, b);
	else
		solve_big(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	char		**split_args;

	if (argc < 2)
		return (error());
	split_args = merge_arg(argc - 1, &argv[1]);
	if (split_args == NULL)
		return (0);
	a.size = count_elements_of(split_args);
	if (find_duplicate(a.size, split_args) == TRUE)
	{
		ft_free("%s", split_args);
		return (error());
	}
	a.begin = create_stack(split_args);
	b.begin = NULL;
	if (a.begin == NULL)
		return (error());
	start_solving(&a, &b);
	exit_program(&a.begin, &b.begin);
	return (0);
}
