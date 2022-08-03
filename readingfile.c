/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:07:27 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 04:05:48 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map(int n, t_data *data)
{
	int		fd;
	char	*line;
	int		x;
	int		nb;

	g_conter = 0;
	fd = open(g_files, O_RDONLY);
	if (fd == -1)
		exit(ft_error(data, E));
	x = 0;
	g_max = 0;
	while (1)
	{
		nb = get_next_line(fd, &line);
		if (x >= n)
			g_line++;
		g_max = (g_max > (int)ft_strlen(line)) ? g_max : (int)ft_strlen(line);
		free(line);
		x++;
		g_conter++;
		if (nb == 0)
			break ;
	}
}

int		file(t_data *data)
{
	int n;
	int fd;

	fd = open(g_files, O_RDONLY);
	if (fd == -1)
		exit(ft_error(data, E));
	count(fd);
	map(g_c, data);
	get_file(fd);
	error(g_c);
	khikhi(data);
	n = check_errors(data);
	if (data->file.cnt != 8)
		exit(ft_error(data, E));
	return (0);
}

int		ft_isdigit(char *cc)
{
	int i;

	i = 0;
	while (cc[i])
	{
		if (cc[i] < 48 || cc[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	filecontrole(char **str, t_data *data)
{
	if (str[0][0] == 'R')
		handle_r(g_lihbity, data);
	if (str[0][0] == 'N' && str[0][1] == 'O')
		handle_no(g_lihbity, data);
	if (str[0][0] == 'S' && str[0][1] == 'O')
		handle_so(g_lihbity, data);
	if (str[0][0] == 'W' && str[0][1] == 'E')
		handle_we(g_lihbity, data);
	if (str[0][0] == 'E' && str[0][1] == 'A')
		handle_ea(g_lihbity, data);
	if (strcmp(&str[0][0], "S") == 0)
		handle_s(g_lihbity, data);
	if (ft_strcmp(&str[0][0], "F") == 0)
		handle_f(g_lihbity, data);
	if (ft_strcmp(&str[0][0], "C") == 0)
		handle_c(g_lihbity, data);
	if (str[0][0] != 'R' && str[0][0] != 'N' && str[0][0] != 'W'
	&& str[0][0] != 'E' && str[0][0] != 'S' && str[0][0] != 'C'
	&& str[0][0] != 'F' && str[0][0] != '1')
		exit(ft_error(data, E));
}

int		count_table(char **str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != NULL)
		cnt++;
	return (cnt);
}
