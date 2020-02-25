/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:27:08 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/15 11:35:48 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2, int s2size);
char	*process(char *line, char *buff, int buffsize);
int		is_nl(char *buff, int size);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		reading(char **line, int fd, char *old_l);
void	make_old(char *old_line, char *buff, int buffsize);
char	*init(char *old_l);
#endif
