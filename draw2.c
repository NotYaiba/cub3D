/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:55:34 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:37:58 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_hors_hit(t_data *data)
{
	int helperu;

	helperu = 0;
	if (data->player.up)
		helperu++;
	while (data->nexthorx >= 0 && data->nexthorx <= COLSIZE * g_max &&
	data->nexthory - helperu >= 0 && data->nexthory - helperu <= COLSIZE
	* g_line)
	{
		if (is_wall(data->nexthorx, data->nexthory - helperu))
		{
			data->wallhorsfound = 1;
			data->horzwallhitx = data->nexthorx;
			data->horzwallhity = data->nexthory;
			break ;
		}
		else
		{
			if (g_nb_sprites)
				if (is_sprite(data->nexthorx, data->nexthory - helperu))
					hadik(data, data->nexthorx, data->nexthory - helperu);
			data->nexthorx += data->stepx;
			data->nexthory += data->stepy;
		}
	}
}

void	get_vert_hit(t_data *data)
{
	int helper;

	helper = 0;
	if (data->player.left)
		helper++;
	while (data->nextverx - helper >= 0 && data->nextverx - helper <= COLSIZE
	* g_max && data->nextvery >= 0 && data->nextvery <= COLSIZE * g_line)
	{
		if (is_wall(data->nextverx - helper, data->nextvery))
		{
			data->wallvertfound = 1;
			data->vertwallhitx = data->nextverx;
			data->vertwallhity = data->nextvery;
			break ;
		}
		else
		{
			if (g_nb_sprites)
				if (is_sprite(data->nextverx - helper, data->nextvery))
					hadik(data, data->nextverx - helper, data->nextvery);
			data->nextverx += data->stepx;
			data->nextvery += data->stepy;
		}
	}
}

void	hadik(t_data *data, double x, double y)
{
	int		sp;
	double	centerx;
	double	centery;

	sp = 0;
	centerx = floor(x / 64) * 64 + 32;
	centery = floor((y) / 64) * 64 + 32;
	while (data->sprites[sp].is_there)
	{
		if (centerx == data->sprites[sp].cenx && centery ==
		data->sprites[sp].ceny)
			return ;
		sp++;
	}
	data->sprites[sp].hors_found = 1;
	data->sprites[sp].xhor = x;
	data->sprites[sp].yhor = y;
	data->sprites[sp].cenx = centerx;
	data->sprites[sp].is_there = 1;
	data->sprites[sp].ceny = centery;
	if (sp + 1 < g_nb_sprites)
		data->sprites[sp + 1].is_there = 0;
}

double	f_min(double one, double two)
{
	return (one > two ? two : one);
}

int		cama(char *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}
