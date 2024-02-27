/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 20:28:20 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	get_color(int value)
{
	value = value % 16;
	if (value <= 7)
		return (value + 40);
	else
		return (value + 92);
}

int	count_elements_of(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	**merge_arg(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	*join;
	char	**split;

	i = 0;
	join = "";
	while (i < argc)
	{
		temp = ft_strjoin(join, argv[i]);
		if (i != 0)
			free(join);
		if (temp == NULL)
			return (NULL);
		join = ft_strjoin(temp, " ");
		free(temp);
		if (join == NULL)
			return (NULL);
		i++;
	}
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	char		**split_args;
	t_move_bt	*solution;

	if (argc < 2)
		return (error());
	split_args = merge_arg(argc - 1, &argv[1]);
	if (split_args == NULL)
		return (0);
	a.size = count_elements_of(split_args);
	b.size = 0;
	if (find_duplicate(a.size, split_args) == TRUE)
	{
		ft_free("%s", split_args);
		return (error());
	}
	a.begin = create_stack(split_args);
	b.begin = NULL;
	if (a.begin == NULL)
		return (error());
	if (is_sorted(&a))
		exit_program(&a.begin, &b.begin);
	// Testing create stack by displaying it
	// ft_printf("A: size = %d\n", a.size);
	// print_stack(a.begin);
	// ft_printf("B: size = %d ==\n", b.size);
	// print_stack(b.begin);
	// (void)solution;
	if (a.size <= 5)
		sort_small(&a, &b);
	else
	{
		solution = solve_bt(&a, &b);

		// ft_printf("\nSOLUTION: \n\n");

		print_solution(solution);
		push_back(&a, &b);
		// swap(&a);
		// ft_printf("\n");
		// ft_printf("A: size = %d\n", a.size);
		// print_stack(a.begin);
		// ft_printf("B: size = %d ==\n", b.size);
		// print_stack(b.begin);

		free(solution);
	}
	// ft_printf("\n");
	// ft_printf("A: size = %d\n", a.size);
	// print_stack(a.begin);
	// ft_printf("B: size = %d ==\n", b.size);
	// print_stack(b.begin);
	exit_program(&a.begin, &b.begin);
	return (0);
}
