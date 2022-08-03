/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:55:15 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:38:40 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++i < lens1)
		str[i] = s1[i];
	i = 0;
	while (i < lens2)
	{
		str[i + lens1] = s2[i];
		i++;
	}
	str[i + lens1] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return (s + i);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *ssrc)
{
	char	*src;
	char	*i;
	int		j;

	src = (char *)ssrc;
	j = 0;
	while (src[j])
		j++;
	i = malloc(j * sizeof(char) + 1);
	if (i == NULL)
		return (NULL);
	ft_strcpy(i, src);
	return (i);
}
