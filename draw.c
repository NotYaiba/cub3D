/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 06:02:28 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 03:26:33 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_data *data)
{
	int col;

	col = 0;
	data->rayangle = data->player.rotangle - (data->player.view / 2.0);
	if (g_nb_sprites)
	{
		if (!(data->sprites = (t_sprites*)malloc(sizeof(t_sprites) *
		g_nb_sprites)))
			return ;
	}
	while (col < data->numr)
	{
		if (g_nb_sprites)
			data->sprites[0].is_there = 0;
		data->rayangle = new_angle(data->rayangle);
		data->wallhorsfound = 0;
		data->wallvertfound = 0;
		hrays(data, data->rayangle, col);
		data->rayangle += (data->ray);
		col++;
	}
	if (g_nb_sprites)
		free(data->sprites);
	screenshot(data);
	mlx_put_image_to_window(data->ptr, data->str, data->image, 0, 0);
}

void	hrays(t_data *data, double angle, int col)
{
	int i;

	angle = new_angle(angle);
	i = 0;
	set_angle_direc(data, angle);
	sethorz(data, angle);
	while (i < g_nb_sprites)
	{
		data->sprites[i].xhor = -1;
		data->sprites[i].yhor = -1;
		data->sprites[i].xvert = -1;
		data->sprites[i].yvert = -1;
		data->sprites[i].h = -1;
		data->sprites[i].vert_found = 0;
		data->sprites[i].hors_found = 0;
		i++;
	}
	get_hors_hit(data);
	setvert(data, angle);
	get_vert_hit(data);
	raycasting_math(data);
	rendering(data, col);
}

void	set_angle_direc(t_data *data, double angle)
{
	data->player.down = ((angle > 0 && angle < M_PI));
	data->player.up = !data->player.down;
	data->player.right = ((angle > 0 && angle < M_PI_2) ||
	(angle < 2 * M_PI && angle > 1.5 * M_PI));
	data->player.left = !data->player.right;
}

void	sethorz(t_data *data, double angle)
{
	data->itry = floor(data->posy / COLSIZE) * COLSIZE;
	data->itry += (data->player.down) ? COLSIZE : 0;
	data->itrx = data->posx + ((data->itry - data->posy) / tan(angle));
	data->stepy = COLSIZE;
	data->stepy *= (data->player.up) ? -1 : 1;
	data->stepx = COLSIZE / tan(angle);
	data->stepx *= (data->player.right && data->stepx < 0) ? -1 : 1;
	data->stepx *= (data->player.left && data->stepx > 0) ? -1 : 1;
	data->nexthorx = data->itrx;
	data->nexthory = data->itry;
}

void	setvert(t_data *data, double angle)
{
	data->itrx = floor(data->posx / COLSIZE) * COLSIZE;
	data->itrx += (data->player.right) ? COLSIZE : 0;
	data->itry = data->posy + ((data->itrx - data->posx) * tan(angle));
	data->stepx = COLSIZE;
	data->stepx *= (data->player.left) ? -1 : 1;
	data->stepy = COLSIZE * tan(angle);
	data->stepy *= (data->player.up && data->stepy > 0) ? -1 : 1;
	data->stepy *= (data->player.down && data->stepy < 0) ? -1 : 1;
	data->nextverx = data->itrx;
	data->nextvery = data->itry;
}
