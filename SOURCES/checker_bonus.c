/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:10:05 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 11:06:19 by cdeville         ###   ########.fr       */
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

void	start_check(t_stack *a, t_stack *b)
{
	if (is_solution_valid(a, b) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**split_args;

	if (argc == 1)
		return (0);
	split_args = merge_arg(argc - 1, &argv[1]);
	if (split_args == NULL)
		return (0);
	a.size = count_elements_of(split_args);
	b.size = 0;
	if (find_duplicate(a.size, split_args) == TRUE)
	{
		ft_free("%s", split_args);
		return (error_check());
	}
	a.begin = create_stack(split_args);
	b.begin = NULL;
	if (a.begin == NULL)
		return (error_check());
	start_check(&a, &b);
	clear_stacks(&a, &b);
	return (0);
}
