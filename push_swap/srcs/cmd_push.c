/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:29:19 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 14:06:17 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst)
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
	else
	{
		*dst = temp;
		temp->next = NULL;
	}
}

void	pa(t_stack **a, t_stack **b, int silent)
{
	push(a, b);
	if (!silent)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int silent)
{
	push(b, a);
	if (!silent)
		write(1, "pb\n", 3);
}
