/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:36:43 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 03:58:44 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			get_image_text(t_data *data)
{
	data->image = mlx_new_image(data->ptr, RX, RY);
	data->texturen = mlx_xpm_file_to_image(data->ptr,
	g_nopath, &data->bpp, &data->size_l);
	if (!data->texturen)
		exit(ft_error(data, EN));
	data->textures = mlx_xpm_file_to_image(data->ptr,
	g_sopath, &data->bpp, &data->size_l);
	if (!data->textures)
		exit(ft_error(data, ES));
	data->texturew = mlx_xpm_file_to_image(data->ptr,
	g_wepath, &data->bpp, &data->size_l);
	if (!data->texturew)
		exit(ft_error(data, EW));
	data->texturee = mlx_xpm_file_to_image(data->ptr,
	g_eapath, &data->bpp, &data->size_l);
	if (!data->texturee)
		exit(ft_error(data, EE));
	data->texturesp = mlx_xpm_file_to_image(data->ptr,
	g_spath, &data->bpp, &data->size_l);
	if (!data->texturesp)
		exit(ft_error(data, ESP));
	get_tex(data);
}

void			get_tex(t_data *data)
{
	data->tex_datan = (int *)mlx_get_data_addr(data->texturen,
	&data->bpp, &data->size_l, &data->endian);
	data->tex_datas = (int *)mlx_get_data_addr(data->textures,
	&data->bpp, &data->size_l, &data->endian);
	data->tex_dataw = (int *)mlx_get_data_addr(data->texturew,
	&data->bpp, &data->size_l, &data->endian);
	data->tex_datae = (int *)mlx_get_data_addr(data->texturee,
	&data->bpp, &data->size_l, &data->endian);
	data->tex_datasp = (int *)mlx_get_data_addr(data->texturesp,
	&data->bpp, &data->size_l, &data->endian);
	data->img_data = (int *)mlx_get_data_addr(data->image,
	&data->bpp, &data->size_l, &data->endian);
}

int				renderin_walls(t_data *data, int i, int col)
{
	int texture_x;
	int texture_y;
	int pixelcolor;
	int *texture;

	if (data->hit_side == 1 && data->player.up)
		texture = data->tex_datan;
	else if (data->hit_side == 1)
		texture = data->tex_datas;
	else if (data->hit_side == 0 && data->player.right)
		texture = data->tex_dataw;
	else
		texture = data->tex_datae;
	if (data->hit_side == 1)
		texture_x = (int)data->wallhitx % 64;
	else
		texture_x = (int)data->wallhity % 64;
	while (i < data->botpixle && i < data->file.tol)
	{
		texture_y = (i - data->toppixle) * ((float)64 / data->wallheight);
		pixelcolor = texture[(64 * texture_y) + texture_x];
		data->img_data[i * data->file.l3erd + col] = pixelcolor;
		i++;
	}
	return (i);
}

double			new_angle(double angle)
{
	if (angle >= (2 * M_PI))
		angle -= (M_PI * 2);
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

void			locate_player(t_data *data, double angle)
{
	data->player.rotangle = angle;
	data->posy = data->y + COLSIZE / 2;
	data->posx = data->x + COLSIZE / 2;
}
