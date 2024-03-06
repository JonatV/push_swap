/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:48:53 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:52:23 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_exec(t_obj_ctl *object_ctl, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(&(object_ctl->a), &(object_ctl->b), 1);
	else if (!ft_strcmp(command, "pb\n"))
		pb(&(object_ctl->a), &(object_ctl->b), 1);
	else if (!ft_strcmp(command, "ra\n"))
		ra(&(object_ctl->a), 1);
	else if (!ft_strcmp(command, "rb\n"))
		rb(&(object_ctl->b), 1);
	else if (!ft_strcmp(command, "rr\n"))
		rr(&(object_ctl->a), &(object_ctl->b), 1);
	else if (!ft_strcmp(command, "rra\n"))
		rra(&(object_ctl->a), 1);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(&(object_ctl->b), 1);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(&(object_ctl->a), &(object_ctl->b), 1);
	else if (!ft_strcmp(command, "sa\n"))
		sa(&(object_ctl->a), 1);
	else if (!ft_strcmp(command, "sb\n"))
		sb(&(object_ctl->b), 1);
	else if (!ft_strcmp(command, "ss\n"))
		ss(&(object_ctl->a), &(object_ctl->b), 1);
	else
		free_exit_checker(object_ctl, 1);
}

static t_obj_ctl	*obj_init(t_stack **a, t_stack **b, char **av, int is_ac_2)
{
	t_obj_ctl	*object_ctl;

	object_ctl = malloc(sizeof(t_obj_ctl));
	if (!object_ctl)
	{
		if (is_ac_2)
			free_av(av);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	object_ctl->a = *a;
	object_ctl->b = *b;
	object_ctl->is_ac_2 = is_ac_2;
	object_ctl->av = av;
	object_ctl->the_line = NULL;
	return (object_ctl);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_obj_ctl	*object_ctl;

	a = NULL;
	b = NULL;
	input_check(ac, av);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	object_ctl = obj_init(&a, &b, av, 2 == ac);
	init_stack_a_checker(&object_ctl);
	start_gnl(object_ctl);
	if (is_sorted(object_ctl->a) && stack_len(object_ctl->b) == 0)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	free_exit_checker(object_ctl, 0);
	return (0);
}
