/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:07:02 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 03:17:28 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data)
{
	data->j = 0;
	g_col = 0;
	g_line = 0;
	g_i = 0;
	g_j = 0;
	g_c = 0;
	g_p = 0;
	data->distance = 0;
	data->itrx = 0;
	data->itry = 0;
	data->player.up = 0;
	data->player.down = 0;
	data->player.right = 0;
	data->player.left = 0;
	data->file.tol = 0;
	data->file.l3erd = 0;
	data->file.floor_r = 0;
	data->file.floor_g = 0;
	data->file.floor_b = 0;
	g_no = 0;
	g_so = 0;
	g_e = 0;
	g_w = 0;
	g_s = 0;
	init2(data);
}

void	init2(t_data *data)
{
	g_v = 0;
	g_h = 0;
	g_p = 0;
	g_nb_sprites = 0;
	data->file.cieling_r = 0;
	data->file.cieling_g = 0;
	data->file.cieling_b = 0;
	data->file.r = 0;
	data->file.no = 0;
	data->file.so = 0;
	data->file.we = 0;
	data->file.ea = 0;
	data->file.s = 0;
	data->file.c = 0;
	data->file.f = 0;
	data->file.cnt = 0;
	file(data);
	data->player.view = 60 * (M_PI / 180);
	data->wall_thicc = 1;
	data->numr = (data->file.l3erd) / data->wall_thicc;
	data->ray = data->player.view / data->numr;
	data->ptr = mlx_init();
	if (g_screen != 1)
		data->str = mlx_new_window(data->ptr, data->file.l3erd,
		data->file.tol, "cub3d");
}

double	distance(t_data *data, double x1, double y1)
{
	return (sqrt((x1 - data->posx) * (x1 - data->posx) +
	(y1 - data->posy) * (y1 - data->posy)));
}

double	distance2(double x, double y, double x1, double y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

void	file_free(void)
{
	if (g_v)
		ft_freee(&g_lihbity);
	if (g_h)
		free(g_li);
	if (g_t)
		free(g_lo);
	if (g_no)
		free(g_nopath);
	if (g_so)
		free(g_sopath);
	if (g_w)
		free(g_wepath);
	if (g_e)
		free(g_eapath);
	if (g_s)
		free(g_spath);
}
