/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:05:35 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:46:16 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tiny(t_stack **head)
{
	t_stack	*high_node;
	int		silent;

	silent = 0;
	high_node = find_max_node(*head);
	if (*head == high_node)
		ra(head, silent);
	else if ((*head)->next == high_node)
		rra(head, silent);
	if ((*head)->next->num < (*head)->num)
		sa(head, silent);
}
