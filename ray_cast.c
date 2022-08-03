/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:07:51 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:45:33 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_math(t_data *data)
{
	HD = (WHF) ? distance(data, HHX, HHY) : INT32_MAX;
	VD = (WVF) ? distance(data, VHX, VHY) : INT32_MAX;
	data->wallhitx = (HD < VD) ? HHX : VHX;
	data->wallhity = (HD < VD) ? HHY : VHY;
	D = (HD < VD) ? HD : VD;
	D = D * cos(data->rayangle - PRA);
	data->hit_side = (HD < VD) ? 1 : 0;
	data->dis_progection = ((RX / 2) / tan(FOV / 2));
	data->wallheight = (COLSIZE / D) * data->dis_progection;
	data->toppixle = (RY / 2) - (data->wallheight / 2);
	data->botpixle = (RY / 2) + (data->wallheight / 2);
	if (g_nb_sprites)
		sprite(data);
}

void	rendering(t_data *data, int col)
{
	int i;
	int j;

	i = 0;
	while (i < data->toppixle)
	{
		data->img_data[i * RX + col] = rgb3(CR, CG, CB);
		i++;
	}
	i = renderin_walls(data, i, col);
	while (i < RY)
	{
		data->img_data[i * RX + col] = rgb3(FR, FG, FB);
		i++;
	}
	j = g_nb_sprites - 1;
	while (j >= 0)
	{
		sprites_math(data, col, j);
		j--;
	}
}

void	sprites_math(t_data *data, int col, int sp)
{
	if (SHX == -1)
		return ;
	if (data->sprites[sp].h == -1)
		data->sprites[sp].h = (RX / data->sprites[sp].dist * 64);
	data->sprites[sp].tx = (RY / 2) - (data->sprites[sp].h / 2);
	rendering_sprites(data, col, sp);
}

void	rendering_sprites(t_data *data, int col, int sp)
{
	int i;
	int j;
	int color;

	i = TOPX;
	j = -1;
	sprites_textures(data, sp);
	while (++j < data->sprites[sp].h)
	{
		if (i > 0 && i < RY && data->sprites[sp].distcenter <= 32 && D > SD)
		{
			data->sprites[sp].texture_y = (i - TOPX) * ((float)64 /
			data->sprites[sp].h);
			color = data->tex_datasp[(64 * data->sprites[sp].texture_y) +
			data->sprites[sp].texture_x];
			if (color != 0x5)
				data->img_data[(int)i * data->file.l3erd + col] = color;
		}
		i++;
	}
}

void	sprites_textures(t_data *data, int sp)
{
	g_y = (data->posy - CY >= 0) ? 1 : 0;
	g_x = (data->posx - CX >= 0) ? 1 : 0;
	if (data->player.up)
	{
		if (HX < CX && g_y)
			data->sprites[sp].texture_x = 32 - data->sprites[sp].distcenter;
		else
			data->sprites[sp].texture_x = 32 + data->sprites[sp].distcenter;
	}
	else if (data->player.down)
	{
		if (HX < CX && !g_y)
			data->sprites[sp].texture_x = 32 + data->sprites[sp].distcenter;
		else
		{
			if (data->posy > CY && data->posy < HY && g_x == 0)
				data->sprites[sp].texture_x = 32 + data->sprites[sp].distcenter;
			else
				data->sprites[sp].texture_x = 32 - data->sprites[sp].distcenter;
		}
	}
	if (data->posy > HY && data->posy < CY && g_x == 0)
		data->sprites[sp].texture_x = 32 - data->sprites[sp].distcenter;
}
