/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mag <mag@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:18:48 by mag               #+#    #+#             */
/*   Updated: 2026/11/05 19:06:16 by mag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (len > (len_s - start))
		len = len_s - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	ssize_t	i;
	ssize_t	len_s1;
	ssize_t	len_s2;

	len_s2 = (ssize_t)ft_strlen(s2);
	len_s1 = (ssize_t)ft_strlen(s1);
	if (s1 == NULL)
		return (ft_substr(s2, 0, len_s2));
	else
		res = malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (++i < len_s1)
		res[i] = s1[i];
	i = -1;
	while (++i < len_s2 + 1)
		res[len_s1 + i] = s2[i];
	return (free(s1), res);
}
