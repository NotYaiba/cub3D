/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 06:28:13 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 03:36:12 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			deal_key(int key, t_data *data)
{
	PRA = new_angle(PRA);
	mlx_clear_window(data->ptr, data->str);
	if (key == 126)
	{
		if (!is_wall2(PX + (cos(PRA) * SPEED), PY + (sin(PRA) * SPEED)))
		{
			PX += cos(PRA) * SPEED;
			PY += sin(PRA) * SPEED;
		}
	}
	else if (key == 125)
	{
		if (!is_wall2(PX - (cos(PRA) * SPEED), PY - (SPEED * sin(PRA))))
		{
			PX -= (SPEED * cos(PRA));
			PY -= (SPEED * sin(PRA));
		}
	}
	else if (key == 124)
		PRA += ROTSPEED * (M_PI / 180);
	else if (key == 123)
		PRA -= ROTSPEED * (M_PI / 180);
	draw_rays(data);
	return (0);
}

static int	test(int key, void *dataa)
{
	if (key == 126)
		((int *)dataa)[0] = 1;
	else if (key == 125)
		((int *)dataa)[1] = 1;
	else if (key == 124)
		((int *)dataa)[3] = 1;
	else if (key == 123)
		((int *)dataa)[4] = 1;
	else if (key == 2)
		((int *)dataa)[5] = 1;
	else if (key == 0)
		((int *)dataa)[6] = 1;
	return (0);
}

static int	test1(int key, void *dataa, t_data *data)
{
	if (key == 126)
		((int *)dataa)[0] = 0;
	else if (key == 125)
		((int *)dataa)[1] = 0;
	else if (key == 124)
		((int *)dataa)[3] = 0;
	else if (key == 123)
		((int *)dataa)[4] = 0;
	else if (key == 2)
		((int *)dataa)[5] = 0;
	else if (key == 0)
		((int *)dataa)[6] = 0;
	if (key == 53)
		exit(ft_error(data, O));
	return (0);
}

static int	test3(void *data)
{
	draw_rays(data);
	if (((int *)g_dataa)[0])
		deal_key(126, data);
	else if (((int *)g_dataa)[1])
		deal_key(125, data);
	if (((int *)g_dataa)[3])
		deal_key(124, data);
	else if (((int *)g_dataa)[4])
		deal_key(123, data);
	else if (((int *)g_dataa)[5])
		deal_key(2, data);
	else if (((int *)g_dataa)[6])
		deal_key(0, data);
	return (0);
}

void		play(void)
{
	t_data data;

	init(&data);
	player(0, 0, &data);
	get_image_text(&data);
	mlx_loop_hook(data.ptr, test3, &data);
	if (g_screen != 1)
	{
		mlx_hook(data.str, 2, 0, test, g_dataa);
		mlx_hook(data.str, 17, 0, key_destroy, g_dataa);
		mlx_key_hook(data.str, test1, g_dataa);
	}
	mlx_loop(data.ptr);
}
