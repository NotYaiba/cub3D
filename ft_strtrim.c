/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:11:28 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:38:30 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_extc(char const *st, char c)
{
	int i;

	i = 0;
	while (st[i])
	{
		if (st[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_existb(char const *str, char const *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_extc(set, str[i]) == 1)
			i++;
		else
			return (i);
	}
	return (0);
}

int		is_existl(char const *str, char const *set, int len)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		if (is_extc(set, str[i]) == 1)
			i--;
		else
			return (i);
	}
	return (len);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		lend;
	int		first_index;
	int		last_index;
	char	*c;

	if (!s1)
		return (NULL);
	lend = 0;
	while (s1[lend])
		lend++;
	first_index = is_existb(s1, set);
	last_index = is_existl(s1, set, lend);
	if (last_index == lend)
		return ("\0");
	c = ft_substr(s1, first_index, (last_index - first_index + 1));
	return (c);
}
