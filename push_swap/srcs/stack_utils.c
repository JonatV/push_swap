/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:32:29 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:55:56 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	is_sorted(t_stack *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

int	stack_len(t_stack *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack	*find_max_node(t_stack *head)
{
	t_stack	*max_node;
	long	max_num;

	if (!head)
		return (NULL);
	max_num = (long)INT_MIN - 1;
	while (head)
	{
		if (head->num > max_num)
		{
			max_num = head->num;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *head)
{
	t_stack	*min_node;
	long	min_num;

	if (!head)
		return (NULL);
	min_num = (long)INT_MAX + 1;
	while (head)
	{
		if (head->num < min_num)
		{
			min_num = head->num;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}
