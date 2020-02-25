/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:52:21 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/15 17:13:22 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int res;

	res = 0;
	if (str)
		while (str[res])
			res++;
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	int		k;
	int		size;

	size = ft_strlen(s);
	k = 0;
	if (!(dst = (char *)malloc(sizeof(*s) * (size + 1))))
		return (0);
	while (k < size)
	{
		dst[k] = s[k];
		k++;
	}
	dst[k] = 0;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, int s2size)
{
	char	*dst;
	int		k;
	int		j;
	int		size;

	k = 0;
	j = 0;
	size = ft_strlen(s1) + s2size + 1;
	if (!(dst = (char *)malloc(sizeof(*s1) * size)))
		return (0);
	while (s1 && s1[k])
		dst[j++] = s1[k++];
	k = 0;
	while (k < s2size && s2[k] != '\n')
		dst[j++] = s2[k++];
	dst[j] = 0;
	return (dst);
}

int		reading(char **line, int fd, char *old_l)
{
	int		bytesread;
	char	*buff;

	bytesread = 0;
	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if ((*line = ft_strdup(old_l)) == 0)
		return (-1);
	while (is_nl(buff, bytesread) == -1
			&& (bytesread = read(fd, buff, BUFFER_SIZE)) > 0)
		*line = process(*line, buff, bytesread);
	make_old(old_l, buff, bytesread);
	free(buff);
	buff = 0;
	return (bytesread > 0 ? 1 : bytesread);
}
