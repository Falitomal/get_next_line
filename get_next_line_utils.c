/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:05:44 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/12 18:05:54 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s && *s != (unsigned char)c)
	s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *buffer)
{
	char	*res;
	size_t	i;
	size_t	x;

	if (!s1)
	{
		s1 = (char *)malloc (1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buffer)
		return (NULL);
	res = malloc(sizeof (char) * ((ft_strlen(s1) + ft_strlen(buffer)) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	x = 0;
	if (s1)
		while (s1[++i] != '\0')
			res[i] = s1[i];
	while (buffer[x] != '\0')
		res[i++] = buffer[x++];
	res[i++] = '\0';
	free(s1);
	return (res);
}

char	*ft_get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[0])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *nline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (nline[i] && nline[i] != '\n')
		i++;
	if (!nline[i])
	{
		free(nline);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(nline) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (nline[i])
		str[j++] = nline[i++];
	str[j] = '\0';
	free(nline);
	return (str);
}
