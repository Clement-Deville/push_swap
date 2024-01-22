/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:18 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 17:28:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../SOURCES/double_chain_list/INCLUDES/dblist.h"
# include "../SOURCES/libft/libft.h"

// TESTER

# include <stdio.h>

//

t_dblist	*create_stack(int argc, char *argv[]);
int			*ft_atoi_edited(const char *nptr);
int			error(void);
int			exit_program(t_dblist *first);

#endif
