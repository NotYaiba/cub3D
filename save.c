/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:43:35 by melkarmi          #+#    #+#             */
/*   Updated: 2020/03/10 01:58:15 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*s_1;
	unsigned char		*s_2;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	if ((s_1 != NULL && s_1 == s_2) || n == 0)
		return (0);
	while (i < n)
	{
		if (s_1[i] != s_2[i])
		{
			return (s_1[i] - s_2[i]);
		}
		i++;
	}
	return (0);
}

static void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = dst;
	if (d == NULL && s == NULL)
		return (NULL);
	if (ft_memcmp(d, s, n) == 0)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

int				save(t_data *data)
{
	int				i;
	unsigned char	*buf;

	i = 0;
	data->width = RX;
	data->height = RY;
	data->bitcount = 24;
	data->width_in_bytes = (((int)RX * data->bitcount + 31) / 32) * 4;
	data->imagesize = data->width_in_bytes * RY;
	data->bisize = 40;
	data->bfffsits = 54;
	data->filesize = 54 + data->imagesize;
	data->biplanes = 1;
	while (i < 54)
		data->header[i++] = 0;
	ft_memcpy(data->header, "BM", 2);
	ft_memcpy(data->header + 2, &data->filesize, 4);
	ft_memcpy(data->header + 10, &data->bfffsits, 4);
	ft_memcpy(data->header + 14, &data->bisize, 4);
	ft_memcpy(data->header + 18, &data->width, 4);
	ft_memcpy(data->header + 22, &data->height, 4);
	ft_memcpy(data->header + 26, &data->biplanes, 2);
	ft_memcpy(data->header + 28, &data->bitcount, 2);
	buf = malloc(data->imagesize);
	return (creat_screen(data, buf));
}

int				creat_screen(t_data *data, unsigned char *buf)
{
	int fd;

	ft_memcpy(data->header + 34, &data->imagesize, 4);
	get_screen(data, buf);
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, data->header, 54);
	write(fd, (char*)buf, data->imagesize);
	close(fd);
	free(buf);
	ft_error(data, "");
	return (0);
}

void			get_screen(t_data *data, unsigned char *buf)
{
	int			row;
	int			col;
	int			x;

	row = RY - 1;
	x = 0;
	while (row >= 0)
	{
		col = 0;
		while (col < RX)
		{
			data->rgb = colorconverter(data, data->img_data[row * RX + col]);
			buf[x * data->width_in_bytes + col * 3 + 0] = data->rgb.b;
			buf[x * data->width_in_bytes + col * 3 + 1] = data->rgb.g;
			buf[x * data->width_in_bytes + col * 3 + 2] = data->rgb.r;
			col++;
		}
		x++;
		row--;
	}
}
