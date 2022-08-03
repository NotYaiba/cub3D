/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:26:04 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/08 20:38:44 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_error(int fd, char **line)
{
	int		a;
	char	*c;

	c = NULL;
	a = read(fd, c, 0);
	if (a < 0 || fd < 0 || !line || BUFFER_SIZE < 0)
	{
		return (-1);
	}
	return (0);
}

int		len_nl(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(*str, '\n') != NULL)
	{
		while ((*str)[i] != '\n')
			i++;
	}
	if (ft_strchr(*str, '\n'))
	{
		tmp = *line;
		*line = ft_substr(*str, 0, i);
		tmp = *str;
		*str = ft_strdup(*str + i + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (0);
}

int		eror(int fd, char **str)
{
	if (fd == -111)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			r;
	char		*tmp;

	if (eror(fd, &str))
		return (1);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (check_error(fd, line) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		((r = read(fd, buf, BUFFER_SIZE)) || 1) && (buf[r] -= buf[r]);
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
		tmp = NULL;
		if (r == 0)
			break ;
	}
	free(buf);
	buf = NULL;
	return (len_nl(&str, line));
}

void	get_map(int l, int fd)
{
	int		i;
	int		j;
	int		nb;
	char	*line;

	j = 1;
	while (1)
	{
		nb = get_next_line(fd, &line);
		if (g_cnt++ >= l)
		{
			i = -1;
			g_mp[j] = malloc(g_max + 2);
			g_mp[j][0] = ' ';
			while (++i < (int)ft_strlen(line))
				g_mp[j][i + 1] = line[i];
			while (++i < g_max + 1)
				g_mp[j][i] = ' ';
			g_mp[j][i] = 0;
			j++;
		}
		free(line);
		if (nb == 0)
			break ;
	}
}
