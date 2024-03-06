/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:57:31 by jveirman          #+#    #+#             */
/*   Updated: 2024/02/26 18:14:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_to_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*current_a;

	while (b)
	{
		target = NULL;
		current_a = a;
		while (current_a)
		{
			if (b->num < current_a->num)
			{
				if (!target)
					target = current_a;
				else if (target->num > current_a->num)
					target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
			b->target = find_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_data_b(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target_to_a(a, b);
}
