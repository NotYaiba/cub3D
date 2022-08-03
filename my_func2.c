/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:38:09 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 23:46:57 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_s(char **str, t_data *data)
{
	if (count_table(str) != 2)
		exit(ft_error(data, ESP));
	g_spath = ft_strdup(str[1]);
	g_s = 1;
	data->file.cnt++;
}

void	handle_f(char **str, t_data *data)
{
	if (str[0][1] != '\0')
		exit(ft_error(data, EF));
	if (count_table(str) != 2)
		exit(ft_error(data, EF));
	if (cama(str[1], ',') != 2)
		exit(ft_error(data, EF));
	g_li = ft_split(str[1], ',');
	g_h = 1;
	if (count_table(g_li) != 3)
		exit(ft_error(data, EF));
	if (data->file.f == 1)
		exit(ft_error(data, EF));
	else
		data->file.f = 1;
	get_floor(g_li, data);
	ft_freee(&g_li);
	g_h = 0;
}

void	get_floor(char **s, t_data *data)
{
	char *t1;
	char *t2;
	char *t3;

	s = NULL;
	t1 = ft_strtrim(g_li[0], " ");
	t2 = ft_strtrim(g_li[1], " ");
	t3 = ft_strtrim(g_li[2], " ");
	data->file.floor_r = ft_atoi(t1);
	data->file.floor_g = ft_atoi(t2);
	data->file.floor_b = ft_atoi(t3);
	if (!ft_isdigit(t1) || !ft_isdigit(t2) || !ft_isdigit(t3))
	{
		free(t1);
		free(t2);
		free(t3);
		exit(ft_error(data, EF));
	}
	free(t1);
	free(t2);
	free(t3);
	if (data->file.floor_r > 255 || data->file.floor_g > 255 ||
	data->file.floor_b > 255)
		exit(ft_error(data, EF));
	data->file.cnt++;
}

void	get_cieling(char **r, t_data *data)
{
	char *t1;
	char *t2;
	char *t3;

	r = NULL;
	t1 = ft_strtrim(g_lo[0], " ");
	t2 = ft_strtrim(g_lo[1], " ");
	t3 = ft_strtrim(g_lo[2], " ");
	data->file.cieling_r = ft_atoi(t1);
	data->file.cieling_g = ft_atoi(t2);
	data->file.cieling_b = ft_atoi(t3);
	if (!ft_isdigit(t1) || !ft_isdigit(t2) || !ft_isdigit(t3))
	{
		free(t1);
		free(t2);
		free(t3);
		exit(ft_error(data, E));
	}
	if (data->file.cieling_r > 255 || data->file.cieling_g > 255 ||
	data->file.cieling_b > 255)
		exit(ft_error(data, EC));
	free(t1);
	free(t2);
	free(t3);
	data->file.cnt++;
}

void	handle_c(char **str, t_data *data)
{
	if (count_table(str) != 2)
		exit(ft_error(data, EC));
	if (cama(str[1], ',') != 2)
		exit(ft_error(data, EC));
	g_lo = ft_split(str[1], ',');
	g_t = 1;
	if (count_table(g_lo) != 3)
		exit(ft_error(data, EC));
	if (data->file.c == 1)
		exit(ft_error(data, EC));
	else
		data->file.c = 1;
	get_cieling(g_lo, data);
	ft_freee(&g_lo);
	g_t = 0;
}
