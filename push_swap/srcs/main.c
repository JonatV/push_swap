/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:03:40 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:46:39 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	input_check(ac, av);
	if (2 == ac)
		av = ft_split(av[1], ' ');
	init_stack_a(&a, av, 2 == ac);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_tiny(&a);
		else
			sort_logics(&a, &b);
	}
	free_exit(&a, av, 2 == ac, 0);
	return (0);
}
