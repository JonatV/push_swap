/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:18:56 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:07:37 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_stack **a, int silent)
{
	swap(a);
	if (!silent)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int silent)
{
	swap(b);
	if (!silent)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int silent)
{
	swap(a);
	swap(b);
	if (!silent)
		write(1, "ss\n", 3);
}
