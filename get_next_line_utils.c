/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:23:59 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/29 13:01:43 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_slen(char *string, char c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *full, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	if (!full)
	{
		full = malloc(1);
		*full = '\0';
	}
	s = (char *)malloc(ft_slen(full, 0) + ft_slen(buffer, 0) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (full[i])
	{
		s[i] = full[i];
		i++;
	}
	while (buffer[j])
		s[i++] = buffer[j++];
	free (full);
	s[i] = '\0';
	return (s);
}

char	*ft_linejoin(char *full)
{
	char	*s;
	int		i;
	int		j;

	j = ft_slen(full, '\n');
	if (!full)
		return (NULL);
	s = (char *)malloc(j + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (i < j + 1)
	{
		s[i] = full[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char *full, int start, int len)
{
	char	*s;
	int		i;
	int		j;

	if (!ft_strchr(full, '\n'))
	{
		free(full);
		return (NULL);
	}	
	s = (char *)malloc((len - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (i < len)
		s[j++] = full[i++];
	s[j] = '\0';
	free (full);
	return (s);
}

char	*ft_strchr(char *full, char c)
{
	int	i;

	if (!full)
		return (NULL);
	i = 0;
	while (full[i])
	{
		if (full[i] == c)
			return (full + i);
		i++;
	}
	return (NULL);
}
