/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:04:14 by jveirman          #+#    #+#             */
/*   Updated: 2024/02/26 18:15:59 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_position(t_stack *head)
{
	int	index;
	int	center;

	if (!head)
		return ;
	index = 0;
	center = stack_len(head) / 2;
	while (head)
	{
		head->index = index;
		if (index <= center)
			head->first_half = 1;
		else
			head->first_half = 0;
		head = head->next;
		index++;
	}
}

static void	set_target_to_b(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*current_b;

	while (a)
	{
		target = NULL;
		current_b = b;
		while (current_b)
		{
			if (a->num > current_b->num)
			{
				if (!target)
					target = current_b;
				else if (target->num < current_b->num)
					target = current_b;
			}
			current_b = current_b->next;
		}
		if (!target)
			a->target = find_max_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	set_cost_to_b(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (a->first_half == 0)
			a->cost = len_a - a->index;
		if (a->target->first_half == 0)
			a->cost += len_b - a->target->index;
		else
			a->cost += a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *head)
{
	long	cheapest_num;
	t_stack	*cheapest_node;

	if (!head)
		return ;
	cheapest_num = LONG_MAX;
	while (head)
	{
		if (head->cost < cheapest_num)
		{
			cheapest_node = head;
			cheapest_num = head->cost;
		}
		head = head->next;
	}
	cheapest_node->is_cheapest = 1;
}

void	set_data_a(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target_to_b(a, b);
	set_cost_to_b(a, b);
	set_cheapest(a);
}
