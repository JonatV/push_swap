/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:10:00 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 19:46:10 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_stack **head, int num)
{
	t_stack	*new_node;
	t_stack	*tail;

	if (!head)
		return ;
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->num = num;
	new_node->is_cheapest = 0;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail = find_last_node(*head);
		tail->next = new_node;
		new_node->prev = tail;
	}
}

void	init_stack_a(t_stack **a, char **av, int is_ac_2)
{
	int		i;
	long	num;

	i = 0;
	if (is_ac_2 && !av)
		free_exit(a, av, 0, 1);
	if (is_ac_2 == 0)
		av++;
	while (av[i])
	{
		if (error_not_digit(av[i]))
			free_exit(a, av, is_ac_2, 1);
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_exit(a, av, is_ac_2, 1);
		if (error_repeat(*a, (int)num))
			free_exit(a, av, is_ac_2, 1);
		add_node(a, (int)num);
		if (find_last_node(*a)->num != num)
			free_exit(a, av, is_ac_2, 1);
		i++;
	}
}
