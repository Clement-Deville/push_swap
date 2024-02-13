/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:18 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/13 16:00:27 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../SOURCES/libft/INCLUDES/libft.h"

// TESTER

# include <stdio.h>

//

# define DEEPNESS 3

typedef struct s_move_bt
{
	int	rr;
	int	rrr;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	count;
}	t_move_bt;

typedef struct s_move_turk
{
	char	*moves;
	int		count;
}	t_move_turk;

typedef struct s_stack
{
	int			size;
	t_dblist	*begin;
}	t_stack;


t_dblist	*create_stack(char *split_args[]);
int			*ft_atoi_edited(const char *nptr);
int			error(void);
int			exit_program(t_dblist **first);
int			push(t_stack *src, t_stack *dest);
t_dblist	*reverse_rotate(t_dblist *begin);
t_dblist	*rotate(t_dblist *begin);
t_move_bt	*solve_bt(t_stack *a, t_stack *b);
void		do_reverse_rotate(t_stack *stack, int count);
void		do_move(t_stack *a, t_stack *b, t_move_bt move);
void		do_rotate(t_stack *stack, int count);
void		do_rrr(t_stack *a, t_stack *b, int count);
void		do_rr(t_stack *a, t_stack *b, int count);
void		init_move(t_move_bt **move);


#endif
