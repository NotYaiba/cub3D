/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 06:54:51 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 07:11:22 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_error(t_data *data, char *c)
{
	int i;

	i = 0;
	data->x = 0;
	if (g_m == 1)
	{
		while (i < g_line + 2)
		{
			free(g_mp[i]);
			i++;
		}
		free(g_mp);
	}
	i = 0;
	if (g_f == 1)
	{
		while (i < g_conter)
		{
			free(g_file[i]);
			i++;
		}
		free(g_file);
	}
	file_free();
	return (ft_putstr(c));
}

void			ft_freee(char ***tab)
{
	int i;

	i = 0;
	while (((*tab)[i]))
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

static void		check0(int i, int j, t_data *data)
{
	if (g_mp[j][i] == '0' || g_mp[j][i] == '2' || g_mp[j][i] == 'N'
	|| g_mp[j][i] == 'S' || g_mp[j][i] == 'W' || g_mp[j][i] == 'E')
	{
		if (g_mp[j][i + 1] == ' ' || g_mp[j][i - 1] == ' '
		|| g_mp[j - 1][i] == ' ' || g_mp[j + 1][i] == ' ')
			exit(ft_error(data, E));
		if (i > (int)ft_strlen(g_mp[j - 1]) ||
		i > (int)ft_strlen(g_mp[j + 1]))
			exit(ft_error(data, EM));
	}
}

static void		checkp(int i, int j, t_data *data)
{
	if (g_mp[j][i] == 'N' || g_mp[j][i] == 'S' || g_mp[j][i] == 'W'
	|| g_mp[j][i] == 'E')
	{
		if (g_p == 0)
			g_p = 1;
		else
			exit(ft_error(data, E));
	}
}

void			khikhi(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < g_line)
	{
		i = 0;
		while (i < (int)ft_strlen(g_mp[j]))
		{
			check0(i, j, data);
			checkp(i, j, data);
			if (g_mp[j][i] != 'N' && g_mp[j][i] != 'S' && g_mp[j][i] != 'W' &&
			g_mp[j][i] != 'E' && g_mp[j][i] != ' ' && g_mp[j][i] != '1' &&
			g_mp[j][i] != '2' && g_mp[j][i] != '0')
				exit(ft_error(data, EM));
			i++;
		}
		j++;
	}
	if (g_p == 0)
		exit(ft_error(data, EM));
}
