/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:27:42 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/27 20:28:05 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

t_bool	find_duplicate(int argc, char *argv[])
{
	t_hash	*htab;

	htab = create_htab(argc, argv, &hash_int);
	if (htab == NULL)
		return (TRUE);
	destroy_htab(htab, argc);
	return (FALSE);
}
