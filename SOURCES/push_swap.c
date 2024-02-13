/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/13 13:34:20 by cdeville         ###   ########.fr       */
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

int	split_len(char **split)
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

t_bool	find_duplicate(int argc, char *argv[])
{
	t_hash	*htab;

	htab = create_htab(argc, argv, &hash_int);
	if (htab == NULL)
		return (TRUE);
	destroy_htab(htab, argc);
	return (FALSE);
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
		ft_printf("\e[0m%d\n", *(int *)(actual->content));
		actual = actual->next;
		if (actual == begin)
			break ;
	}
	return ;
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
	a.size = split_len(split_args);
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
	// Testing create stack by displaying it
	ft_printf("A: size = %d\n", a.size);
	print_stack(a.begin);
	ft_printf("B: size = %d ==\n", b.size);
	print_stack(b.begin);
	solution = solve_bt(&a, &b);
	ft_printf("A: size = %d\n", a.size);
	print_stack(a.begin);
	ft_printf("B: size = %d ==\n", b.size);
	print_stack(b.begin);
	// while (a.size)
	// {
	// 	push(&a, &b);
	// 	ft_printf("A: size = %d\n", a.size);
	// 	print_stack(a.begin);
	// 	ft_printf("B: size = %d\n", b.size);
	// 	print_stack(b.begin);
	// }
	free(solution);
	exit_program(&a.begin);
	exit_program(&b.begin);
	return (0);
}
