/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:00 by melkarmi          #+#    #+#             */
/*   Updated: 2019/10/23 19:26:55 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t c, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *ssrc);

#endif
