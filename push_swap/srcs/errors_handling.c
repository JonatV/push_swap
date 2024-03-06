/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:17:23 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/01 20:42:36 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_not_digit(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
			return (1);
		if (!ft_isdigit(str[i + 1]))
			return (1);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_repeat(t_stack *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **head)
{
	t_stack	*temp;
	t_stack	*current;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_exit(t_stack **a, char **av, int is_ac_2, int is_failure)
{
	if (a)
		free_stack(a);
	if (is_ac_2)
		free_av(av);
	if (is_failure)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(0);
}
