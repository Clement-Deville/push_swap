/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:18 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/02 16:02:03 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../SOURCES/libft/INCLUDES/libft.h"

// TESTER

# include <stdio.h>

//

t_dblist	*create_stack(char *split_args[]);
int			*ft_atoi_edited(const char *nptr);
int			error(void);
int			exit_program(t_dblist **first);

#endif
