/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:02:57 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/15 17:17:03 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_nl(char *buff, int size)
{
	int k;

	k = 0;
	while (k < size)
	{
		if (buff[k] == '\n')
			return (k);
		k++;
	}
	return (-1);
}

char	*process(char *line, char *buff, int buffsize)
{
	char	*tmp;

	tmp = ft_strjoin(line, buff, buffsize);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (tmp);
}

void	make_old(char *old_line, char *buff, int buffsize)
{
	int pos;
	int k;

	k = 0;
	pos = is_nl(buff, buffsize) + 1;
	if (pos >= 1)
	{
		while (pos + k < buffsize)
		{
			old_line[k] = buff[k + pos];
			k++;
		}
	}
	old_line[k] = 0;
}

char	*init(char *old_l)
{
	char	*tmp;

	if (old_l == NULL && BUFFER_SIZE > 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE))))
			return (NULL);
		tmp[0] = 0;
		return (tmp);
	}
	return (old_l);
}

int		get_next_line(int fd, char **line)
{
	static char		*old_l = NULL;
	int				res;

	if (BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if ((old_l = init(old_l)) == NULL)
		return (-1);
	if (is_nl(old_l, ft_strlen(old_l)) >= 0)
	{
		*line = process(ft_strdup(""), old_l, ft_strlen(old_l));
		make_old(old_l, old_l, ft_strlen(old_l));
		res = *line == NULL ? -1 : 1;
	}
	else
		res = reading(line, fd, old_l);
	if (res <= 0)
	{
		free(old_l);
		old_l = NULL;
	}
	return (res);
}
