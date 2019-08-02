/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:20:02 by moguy             #+#    #+#             */
/*   Updated: 2019/01/15 22:00:02 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*linecpy(char *stat)
{
	int		i;
	int		j;
	int		size;
	char	*temp;
	char	*line;

	i = 0;
	j = 0;
	size = ft_strlen(stat);
	if (!(line = ft_strnew(size)))
		return (NULL);
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (!(temp = ft_strnew(size - i)))
		return (NULL);
	i++;
	while (stat[i])
		temp[j++] = stat[i++];
	ft_bzero(stat, size);
	ft_strcpy(stat, temp);
	ft_strdel(&temp);
	return (line);
}

int		reader(const int fd, char **stat, int cycle, size_t size)
{
	int		h;
	char	temp[BUFF_SIZE + 1];

	while ((h = read(fd, &temp, BUFF_SIZE)) > 0)
	{
		temp[h] = '\0';
		ft_strcat(*stat, temp);
		if (ft_strchr(temp, '\n') != NULL)
			return (1);
		if (!(*stat = ft_realloc(*stat, ((BUFF_SIZE * cycle) + size))))
			return (-1);
		cycle++;
	}
	if (h == -1)
		return (-1);
	if (*stat[0])
		return (1);
	ft_strdel(stat);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char *stat[4865] = {NULL};
	int			k;
	size_t		size;
	int			cycle;

	if (fd < 0 || fd > 4864 || !line || BUFF_SIZE < 1)
		return (-1);
	size = 0;
	cycle = 2;
	if (!stat[fd])
		if (!(stat[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (stat[fd] && (size = ft_strlen(stat[fd])))
		if (!(stat[fd] = (ft_realloc(stat[fd], (BUFF_SIZE + size)))))
			return (-1);
	if ((ft_strchr(stat[fd], '\n')) == NULL)
		if ((k = (reader(fd, &stat[fd], cycle, size))) < 1)
			return (k);
	if (!stat[fd] && !stat[fd][0])
		return (0);
	if (!(*line = linecpy(stat[fd])))
		return (-1);
	return (1);
}
