/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:10:05 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 20:24:01 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	error_check()
{
	char	*str;

	str = get_next_line(0);
	if (ft_strncmp(str, "error\n", 7) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	if (find_duplicate(argc, argv))
		return (error_check());
	a.begin = create_stack(argv);
	if (a.begin == NULL)
		return (error_check());
	if (is_solution_valid(&a, &b) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free("%d %d", a.begin, b.begin);
	return (0);
}
