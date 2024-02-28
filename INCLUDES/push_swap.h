/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:22:18 by cdeville          #+#    #+#             */
/*   Updated: 2024/02/28 19:57:38 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../SOURCES/libft/INCLUDES/libft.h"

// TESTER

# include <stdio.h>

//

# define DEEPNESS 1
# define END_FLAG -1

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
int			exit_program(t_dblist **begin_a, t_dblist **begin_b);
void		swap(t_stack *stack);
int			push(t_stack *src, t_stack *dest);
void		reverse_rotate(t_stack *stack);
void		rotate(t_stack *stack);
void		solve_big(t_stack *a, t_stack *b);
void		do_reverse_rotate(t_stack *stack, int count, char *key);
void		do_move(t_stack *a, t_stack *b, t_move_bt *move);
void		do_rotate(t_stack *stack, int count, char *key);
void		do_rrr(t_stack *a, t_stack *b, int count);
void		do_rr(t_stack *a, t_stack *b, int count);
void		do_push(t_stack *src, t_stack *dest, int count, char *key);
void		do_swap(t_stack *stack, char *key);
void		undo_move(t_stack *a, t_stack *b, t_move_bt *move);
void		init_move(t_move_bt *move);
t_move_bt	get_best_move(t_stack *a, t_stack *b, int index_a, int index_b);
t_bool		find_duplicate(int argc, char *argv[]);

char		**merge_arg(int argc, char **argv);
int			count_elements_of(char **split);

void		init_solve(void *actual);
void		init_move(t_move_bt *move);

void		print_stack(t_dblist *begin);
void		print_move(int count, char *key);
void		print_solution(t_move_bt *solution);
void		print_after(t_move_bt *solution, int index);
void		print_before(t_move_bt *solution, t_move_bt *actual, int index);
void		print_full(t_move_bt move);

void		push_back(t_stack *a, t_stack *b);
void		sort_three(t_stack *a);
t_bool		is_sorted(t_stack *stack);
int			target_b(int value, t_stack *stack);

int			actual_value(t_dblist *actual);
int			prev_value(t_dblist *actual);
int			next_value(t_dblist *actual);
t_bool		value_is_smaller(int value, t_dblist *actual);
t_bool		value_is_bigger(int value, t_dblist *actual);

void		sort_small(t_stack *a, t_stack *b);

int			target_a(int value, t_stack *stack);
void		do_move_back(t_stack *a, t_stack *b, t_move_bt *move);
void		put_small_on_top(t_stack *a);
void		del_content(int *number);
void		clear_stacks(t_stack *a, t_stack *b);

t_bool		is_solution_valid(t_stack *a, t_stack *b);
t_dblist	*create_stack_bonus(char *argv[]);
int			error_check(void);
int			check_pa(t_stack *a, t_stack *b);
int			check_pb(t_stack *a, t_stack *b);
int			check_sa(t_stack *a);
int			check_rra(t_stack *a);
int			check_ra(t_stack *a);
int			check_rb(t_stack *b);
int			check_rrb(t_stack *b);
int			check_sb(t_stack *b);
int			check_rr(t_stack *a, t_stack *b);
int			check_rrr(t_stack *a, t_stack *b);

#endif
