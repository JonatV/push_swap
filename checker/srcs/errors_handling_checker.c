/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:05:22 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:55:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_exit_checker(t_obj_ctl *object_ctl, int is_failure)
{
	if (object_ctl->a)
		free_stack(&(object_ctl->a));
	if (object_ctl->b)
		free_stack(&(object_ctl->b));
	if (object_ctl->is_ac_2)
		free_av(object_ctl->av);
	if (object_ctl->the_line)
		free(object_ctl->the_line);
	if (is_failure)
	{
		write(1, "Error\n", 6);
		free(object_ctl);
		object_ctl = NULL;
		exit(EXIT_FAILURE);
	}
	free(object_ctl);
	object_ctl = NULL;
	exit(EXIT_SUCCESS);
}

void	init_stack_a_checker(t_obj_ctl **object_ctl)
{
	int		i;
	long	num;

	i = 0;
	if ((*object_ctl)->is_ac_2 && !(*object_ctl)->av)
		free_exit_checker(*object_ctl, 1);
	if ((*object_ctl)->is_ac_2 == 0)
		(*object_ctl)->av++;
	while ((*object_ctl)->av[i])
	{
		if (error_not_digit((*object_ctl)->av[i]))
			free_exit_checker(*object_ctl, 1);
		num = ft_atol((*object_ctl)->av[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_exit_checker(*object_ctl, 1);
		if (error_repeat((*object_ctl)->a, (int)num))
			free_exit_checker(*object_ctl, 1);
		add_node(&((*object_ctl)->a), (int)num);
		if (find_last_node((*object_ctl)->a)->num != num)
			free_exit_checker(*object_ctl, 1);
		i++;
	}
}
