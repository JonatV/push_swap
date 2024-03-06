/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:12:39 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:05:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = find_last_node(*head);
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *head;
	(*head)->prev = tail;
	*head = tail;
}

void	rra(t_stack **a, int silent)
{
	rev_rotate(a);
	if (!silent)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int silent)
{
	rev_rotate(b);
	if (!silent)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int silent)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!silent)
		write(1, "rrr\n", 4);
}
