/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:52:46 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:07:09 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = find_last_node(*head);
	tail->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack **a, int silent)
{
	rotate(a);
	if (!silent)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int silent)
{
	rotate(b);
	if (!silent)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int silent)
{
	rotate(a);
	rotate(b);
	if (!silent)
		write(1, "rr\n", 3);
}
