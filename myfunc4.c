/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:18:03 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:39:13 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player(int x, int y, t_data *data)
{
	g_i = 0;
	while (g_i <= g_line)
	{
		g_j = 0;
		while (g_j <= (int)ft_strlen(g_mp[g_i]))
		{
			data->x = x;
			data->y = y;
			if (g_mp[g_i][g_j] == 'N')
				locate_player(data, M_PI * 1.5);
			if (g_mp[g_i][g_j] == 'S')
				locate_player(data, (M_PI) / 2);
			if (g_mp[g_i][g_j] == 'W')
				locate_player(data, M_PI);
			if (g_mp[g_i][g_j] == 'E')
				locate_player(data, 0);
			if (g_mp[g_i][g_j] == '2')
				g_nb_sprites++;
			x += COLSIZE;
			g_j++;
		}
		g_i++;
		y += COLSIZE;
		x = 0;
	}
}

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	sprite(t_data *data)
{
	int sp;

	sp = 0;
	while (sp < g_nb_sprites && data->sprites[sp].is_there)
	{
		data->hit_side2 = (SHF == 1) ? 1 : 0;
		data->sprites[sp].dist = distance(data, CX, CY);
		data->sprites[sp].hitx = SD * cos(data->rayangle) + PX;
		data->sprites[sp].hity = SD * sin(data->rayangle) + PY;
		data->sprites[sp].distcenter = distance2(CX, CY, HX, HY);
		sp++;
	}
	sortdist(data);
}

void	sortdist(t_data *data)
{
	int			i;
	int			sorted;
	t_sprites	tmp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < g_nb_sprites - 1)
		{
			if (data->sprites[i].dist > data->sprites[i + 1].dist)
			{
				sorted = 0;
				tmp = data->sprites[i];
				data->sprites[i] = data->sprites[i + 1];
				data->sprites[i + 1] = tmp;
			}
			i++;
		}
	}
}
