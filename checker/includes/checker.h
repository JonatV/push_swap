/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:42:53 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/06 12:09:49 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../push_swap/includes/push_swap.h"
# include <fcntl.h>

typedef struct s_obj_ctl
{
	t_stack	*a;
	t_stack	*b;
	int		is_ac_2;
	char	**av;
	char	*the_line;
}	t_obj_ctl;

void	free_exit_checker(t_obj_ctl *object_ctl, int is_failure);
void	init_stack_a_checker(t_obj_ctl **object_ctl);
void	check_exec(t_obj_ctl *object_ctl, char *command);
void	start_gnl(t_obj_ctl *object_ctl);

#endif
