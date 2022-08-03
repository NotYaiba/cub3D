/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:05:54 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 23:43:56 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, char *src, size_t s)
{
	size_t			i;

	i = 0;
	while (i + 1 < s && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (s)
		dst[i] = '\0';
	return (ft_strlen(src));
}

int		key_destroy(int key, t_data *data)
{
	key = (int)data->x;
	exit(0);
}

int		ft_atoi(const char *s)
{
	char			*str;
	long long		x;
	long long		n;

	str = (char *)s;
	x = 0;
	n = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (x < 0 && n < 0)
			return (0);
		if (x < 0 && n > 0)
			return (-1);
		x = x * 10 + (*str - 48);
		str++;
	}
	return (x * n);
}

void	screenshot(t_data *data)
{
	if (g_screen == 1)
	{
		save(data);
		exit(0);
	}
}

int		ft_strcmp(const char *s_1, const char *s_2)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)s_1;
	s2 = (unsigned char *)s_2;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
