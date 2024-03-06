/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:58:17 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 11:50:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				first_half;
	int				cost;
	int				is_cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// ---------- ERRORS HANDLING
void	input_check(int ac, char **av);
int		error_not_digit(char *str);
int		error_repeat(t_stack *a, int num);
void	free_stack(t_stack **head);
void	free_exit(t_stack **a, char **av, int is_ac_2, int is_failure);
void	free_av(char **av);

// ---------- STACK INIT
void	add_node(t_stack **head, int num);
void	init_stack_a(t_stack **a, char **av, int is_ac_2);

// ---------- STACK UTILS
t_stack	*find_last_node(t_stack *head);
int		is_sorted(t_stack *head);
int		stack_len(t_stack *head);
t_stack	*find_max_node(t_stack *head);
t_stack	*find_min_node(t_stack *head);

// ---------- SORT LOGICS
void	sort_tiny(t_stack **head);
void	sort_logics(t_stack **a, t_stack**b);

// ---------- SORT UTILS
t_stack	*find_cheapest_node(t_stack *head);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	move_top(t_stack **head, t_stack *to_top, int is_stack_a);
void	the_final_rotations(t_stack **a);

// ---------- SET DATA
void	set_position(t_stack *head);
void	set_cheapest(t_stack *head);
void	set_data_a(t_stack *a, t_stack *b);
void	set_data_b(t_stack *a, t_stack *b);

// ---------- MOVE COMMANDS
void	ra(t_stack **a, int silent);
void	rb(t_stack **b, int silent);
void	rr(t_stack **a, t_stack **b, int silent);
void	rra(t_stack **a, int silent);
void	rrb(t_stack **b, int silent);
void	rrr(t_stack **a, t_stack **b, int silent);
void	sa(t_stack **a, int silent);
void	sb(t_stack **b, int silent);
void	ss(t_stack **a, t_stack **b, int silent);
void	pa(t_stack **a, t_stack **b, int silent);
void	pb(t_stack **a, t_stack **b, int silent);

#endif