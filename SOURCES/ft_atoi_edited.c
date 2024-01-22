/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_edited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:50:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 17:14:07 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	ft_isspace(int c)
{
	if ((c >= 8 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isnum(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	*ft_atoi_edited(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;
	int	has_changed;
	int	*ptr_nb;

	has_changed = 0;
	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (ft_isnum(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
		has_changed = 1;
	}
	nb *= sign;
	if (!has_changed)
		return (NULL);
	ptr_nb = malloc(sizeof(int));
	*ptr_nb = nb;
	return (ptr_nb);
}
