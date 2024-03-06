/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:48:10 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/05 10:46:57 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	input_check(int ac, char **av)
{
	long	num;

	if (1 == ac)
		exit(0);
	if (2 == ac)
	{
		if (!av[1][0])
			exit(0);
		if (words_counts(av[1], ' ') == 1)
		{
			if (error_not_digit(av[1]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			num = ft_atol(av[1]);
			if (num > INT_MAX || num < INT_MIN)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			else
				exit(0);
		}
	}
}
