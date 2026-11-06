/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mag <mag@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:18:53 by mag               #+#    #+#             */
/*   Updated: 2026/11/06 21:44:06 by mag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_more(char *res, int fd)
{
	char	*buf;
	ssize_t	read_size;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(res), NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(res), free(buf), NULL);
		buf[read_size] = 0;
		res = ft_strjoin(res, buf);
		if (!res)
			return (free(buf), NULL);
		if (ft_strchr(buf, '\n') != NULL || read_size == 0)
			return (free(buf), res);
	}
	return (free(buf), res);
}

static char	*split_line(char *tmp, char **stash)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			res = ft_substr(tmp, 0, i + 1);
			if (!res)
				return (NULL);
			*stash = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
			if (!*stash)
				return (free(res), NULL);
			return (res);
		}
		i++;
	}
	res = ft_substr(tmp, 0, i);
	if (!res)
		return (NULL);
	return (free(*stash), *stash = NULL, res);
}

static char	*get_stash(char **stash)
{
	char	*res;

	if (!*stash)
		return (ft_substr("", 0, 0));
	res = ft_substr(*stash, 0, ft_strlen(*stash));
	free(*stash);
	*stash = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		*tmp;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = get_stash(&stash);
	if (!res)
		return (NULL);
	res = read_more(res, fd);
	if (!res)
		return (free(stash), stash = NULL, NULL);
	if (ft_strlen(res) == 0)
		return (free(res), NULL);
	tmp = res;
	res = split_line(tmp, &stash);
	free(tmp);
	if (!res)
		return (free(stash), stash = NULL, NULL);
	return (res);
}
