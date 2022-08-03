/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:42:57 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 23:44:45 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_r(char **str, t_data *data)
{
	if (str[0][1] != '\0')
		exit(ft_error(data, ER));
	if (count_table(str) != 3)
		exit(ft_error(data, ER));
	if (data->file.r == 1)
		exit(ft_error(data, ER));
	else
		data->file.r = 1;
	if (!ft_isdigit(str[1]) || !ft_isdigit(str[2]))
		exit(ft_error(data, ER));
	else
	{
		data->file.l3erd = (ft_atoi(str[1]) > 0) ? ft_atoi(str[1]) : 2560;
		data->file.tol = (ft_atoi(str[2]) > 0) ? ft_atoi(str[2]) : 1440;
		if (data->file.l3erd == 0 || data->file.tol == 0)
			exit(ft_error(data, E));
		if (data->file.l3erd > 2560)
			data->file.l3erd = 2560;
		if (data->file.tol > 1440)
			data->file.tol = 1440;
		data->file.cnt++;
	}
}

void	handle_no(char **str, t_data *data)
{
	if (str[0][2] != '\0')
		exit(ft_error(data, EN));
	if (count_table(str) != 2)
		exit(ft_error(data, EN));
	if (data->file.no == 1)
		exit(ft_error(data, EN));
	else
		data->file.no = 1;
	g_nopath = ft_strdup(str[1]);
	g_no = 1;
	data->file.cnt++;
}

void	handle_so(char **str, t_data *data)
{
	if (str[0][2] != '\0')
		exit(ft_error(data, ES));
	if (count_table(str) != 2)
		exit(ft_error(data, ES));
	if (data->file.so == 1)
		exit(ft_error(data, ES));
	else
		data->file.so = 1;
	g_sopath = ft_strdup(str[1]);
	g_so = 1;
	data->file.cnt++;
}

void	handle_we(char **str, t_data *data)
{
	if (str[0][2] != '\0')
		exit(ft_error(data, EW));
	if (count_table(str) != 2)
		exit(ft_error(data, EW));
	if (data->file.we == 1)
		exit(ft_error(data, EW));
	else
		data->file.we = 1;
	g_wepath = ft_strdup(str[1]);
	g_w = 1;
	data->file.cnt++;
}

void	handle_ea(char **str, t_data *data)
{
	if (str[0][2] != '\0')
		exit(ft_error(data, EE));
	if (count_table(str) != 2)
		exit(ft_error(data, EE));
	if (data->file.ea == 1)
		exit(ft_error(data, EE));
	else
		data->file.ea = 1;
	g_eapath = ft_strdup(str[1]);
	g_e = 1;
	data->file.cnt++;
}
