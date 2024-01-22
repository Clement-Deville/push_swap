/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:08:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/22 17:25:25 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBLIST_H
# define DBLIST_H

# include <stdlib.h>

typedef struct s_dblist
{
	struct s_dblist	*prev;
	struct s_dblist	*next;
	void			*content;
}	t_dblist;

t_dblist	*ft_dblstnew(void *content);
t_dblist	*ft_dblstadd_after(t_dblist *actual, t_dblist *new);
void		ft_dblstadd_before(t_dblist *actual, t_dblist *new);
t_dblist	*ft_dblstfirst(void *content);


#endif
