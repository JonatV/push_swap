/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:43:05 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:13:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_cheapest_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->is_cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b, 0);
	set_position(*a);
	set_position(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b, 0);
	set_position(*a);
	set_position(*b);
}

void	move_top(t_stack **head, t_stack *to_top, int is_stack_a)
{
	while (*head != to_top)
	{
		if (is_stack_a)
		{
			if (to_top->first_half)
				ra(head, 0);
			else
				rra(head, 0);
		}
		else
		{
			if (to_top->first_half)
				rb(head, 0);
			else
				rrb(head, 0);
		}
	}
}

void	the_final_rotations(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_min_node(*a);
	while (*a != min_node)
	{
		if (min_node->first_half)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
