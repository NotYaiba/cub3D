/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:59:34 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 03:56:46 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_file(int fd)
{
	int		i;
	int		j;
	int		nb;
	char	*line;

	j = 0;
	g_f = 1;
	g_file = malloc(sizeof(char*) * g_conter);
	while (1)
	{
		nb = get_next_line(fd, &line);
		i = 0;
		g_file[j] = malloc(ft_strlen(line) + 1);
		while (line[i] != '\0')
		{
			g_file[j][i] = line[i];
			i++;
		}
		g_file[j][i] = '\0';
		j++;
		free(line);
		if (nb == 0)
			break ;
	}
}

void	error(int l)
{
	int fd;
	int j;

	fd = open(g_files, O_RDONLY);
	j = -1;
	g_m = 1;
	g_mp = malloc(sizeof(char*) * (g_line + 2));
	g_mp[0] = malloc(g_max + 2);
	g_mp[g_line + 1] = malloc(g_max + 2);
	while (++j < g_max + 1)
	{
		g_mp[0][j] = ' ';
		g_mp[g_line + 1][j] = ' ';
	}
	(g_mp[0][g_max + 1] &= 0) || (g_mp[g_line + 1][g_max + 1] &= 0) || (j = 1);
	g_cnt = 0;
	get_map(l, fd);
	g_m = 1;
}

int		checker(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

int		check_errors(t_data *data)
{
	static int		t = 0;
	char			*r;

	while (t < g_conter - g_line)
	{
		if ((g_file[t][0] == '\0' || checker(g_file[t]) == 1) && (t++ || 1))
			continue ;
		if (g_file[t][(int)ft_strlen(g_file[t]) - 1] == ',')
			exit(ft_error(data, E));
		r = ft_strtrim(g_file[t], " ");
		if (r[0] == 'N' || r[0] == 'E' || r[0] == 'W' || r[0] == 'S')
			g_lihbity = ft_split2(r, ' ');
		else
			g_lihbity = ft_split(r, ' ');
		g_v = 1;
		free(r);
		filecontrole(g_lihbity, data);
		g_v = 0;
		ft_freee(&g_lihbity);
		t++;
	}
	return (t);
}

int		count(int fd)
{
	int		nb;
	char	*r;
	char	*line;

	fd = open(g_files, O_RDONLY);
	g_c = 0;
	while (1)
	{
		nb = get_next_line(fd, &line);
		if (line[0] == '\0' || checker(line) == 1)
		{
			free(line);
			g_c++;
			continue ;
		}
		r = ft_strtrim(line, " ");
		free(line);
		if (r[0] == '1' || nb == 0)
			break ;
		free(r);
		g_c++;
	}
	get_next_line(-111, &line);
	free(r);
	return (0);
}
