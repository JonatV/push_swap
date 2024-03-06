/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:10:46 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:14:12 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest_node(*a);
	if (cheapest_node->target->first_half && cheapest_node->first_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->target->first_half)
		&& !(cheapest_node->first_half))
		rev_rotate_both(a, b, cheapest_node);
	move_top(a, cheapest_node, 1);
	move_top(b, cheapest_node->target, 0);
	pb(a, b, 0);
}

void	sort_logics(t_stack **a, t_stack**b)
{
	int	stack_a_len;

	stack_a_len = stack_len(*a);
	if (stack_a_len-- > 3 && !is_sorted(*a))
		pb(a, b, 0);
	if (stack_a_len-- > 3 && !is_sorted(*a))
		pb(a, b, 0);
	while (stack_a_len-- > 3 && !is_sorted(*a))
	{
		set_data_a(*a, *b);
		move_to_b(a, b);
	}
	sort_tiny(a);
	while (*b)
	{
		set_data_b(*a, *b);
		move_top(a, (*b)->target, 1);
		pa(a, b, 0);
	}
	set_position(*a);
	the_final_rotations(a);
}
