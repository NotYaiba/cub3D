/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:27:11 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 23:48:41 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb3(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

int				main(int argc, char **argv)
{
	g_screen = 0;
	if (argc < 2 || argc > 3)
		exit(ft_putstr("Error\n IN ARGS"));
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			g_screen = 1;
		else
			exit(ft_putstr("Error\n"));
	}
	if (!ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub"))
		g_files = argv[1];
	else
		exit(ft_putstr("Error\n"));
	setbuf(stdout, NULL);
	play();
}

t_rgb			colorconverter(t_data *data, int hexvalue)
{
	data->rgb.r = ((hexvalue >> 16) & 0xFF);
	data->rgb.g = ((hexvalue >> 8) & 0xFF);
	data->rgb.b = ((hexvalue) & 0xFF);
	return (data->rgb);
}

int				is_wall(int x, int y)
{
	int col;
	int row;

	col = floor(y / COLSIZE);
	row = floor(x / COLSIZE);
	if (g_mp[col][row] == '1')
		return (1);
	return (0);
}

int				is_wall2(int x, int y)
{
	int col;
	int row;

	col = floor(y / COLSIZE);
	row = floor(x / COLSIZE);
	if (g_mp[col][row] == '1' || g_mp[col][row] == '2' || g_mp[col][row] == ' ')
		return (1);
	return (0);
}
