/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_edited.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:50:36 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/20 17:23:58 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static int	is_beyond_int(long long nb)
{
	if (nb < INT_MIN || nb > INT_MAX)
	{
		ft_printf("At least one argument is beyond the int range!\n");
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	ft_isspace(int c)
{
	if ((c >= 8 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isnum(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

static int	define_sign(const char *nptr, int i)
{
	if (nptr[i] == '-')
		return (-1);
	else
		return (1);
}

int	*ft_atoi_edited(const char *nptr)
{
	long long	nb;
	int			i;
	int			sign;
	int			has_changed;
	int			*ptr_nb;

	has_changed = 0;
	i = 0;
	nb = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = define_sign(nptr, i);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isnum(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - 48;
		has_changed = 1;
		i++;
	}
	nb *= sign;
	if (!has_changed || is_beyond_int(nb))
		return (NULL);
	ptr_nb = malloc(sizeof(int));
	if (ptr_nb == NULL)
		return (NULL);
	*ptr_nb = (int)nb;
	return (ptr_nb);
}
