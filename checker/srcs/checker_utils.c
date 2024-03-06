/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:23:07 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/06 12:26:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static char	*read_file(int fd)
{
	char	*res;
	int		nbr_bytes;

	res = malloc(sizeof(char) * (1 + 1));
	if (!res)
		return (NULL);
	nbr_bytes = read(fd, res, 1);
	if (nbr_bytes <= 0)
	{
		free(res);
		return (NULL);
	}
	res[nbr_bytes] = '\0';
	return (res);
}

static char	*process_line(char **stash)
{
	char	*line;
	char	*leftovers;
	int		len;

	len = 0;
	while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
		len++;
	if ((*stash)[len] == '\n')
	{
		line = ft_substr(*stash, 0, len + 1);
		leftovers = ft_substr(*stash, len + 1, ft_strlen(*stash) - (len + 1));
		free(*stash);
		*stash = leftovers;
		return (line);
	}
	return (NULL);
}

static char	*get_next_line_helper(char **stash, int fd)
{
	char		*res;
	char		*char_read;
	char		*line;

	line = process_line(stash);
	if (line)
		return (line);
	char_read = read_file(fd);
	if (!char_read)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (*line)
			return (line);
		free(line);
		return (NULL);
	}
	res = ft_strjoin(*stash, char_read);
	free(*stash);
	*stash = res;
	free(char_read);
	return (get_next_line_helper(stash, fd));
}

static char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	return (get_next_line_helper(&stash, fd));
}

void	start_gnl(t_obj_ctl *object_ctl)
{
	object_ctl->the_line = get_next_line(STDIN_FILENO);
	while (object_ctl->the_line)
	{
		check_exec(object_ctl, object_ctl->the_line);
		free(object_ctl->the_line);
		object_ctl->the_line = NULL;
		object_ctl->the_line = get_next_line(STDIN_FILENO);
	}
	if (object_ctl->the_line)
	{
		free(object_ctl->the_line);
		object_ctl->the_line = NULL;
	}
}
