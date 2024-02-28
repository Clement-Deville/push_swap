/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:14:19 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 09:14:32 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

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
