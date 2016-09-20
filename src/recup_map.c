/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:03:37 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:29 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		**recup_map(char *file)
{
	int				fd;
	int				**map;
	t_params_map	tmap;
	int				j;

	fd = open(file, O_RDONLY);
	tmap = ft_get_params(fd);
	j = 0;
	map = (int**)malloc(sizeof(int *) * tmap.nb_lines + 1);
	while (j < tmap.nb_lines)
	{
		map[j] = ft_get_next_line(fd);
		j++;
	}
	return (map);
}

char	*ft_strjoin(char *line, char buff)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(line) + ft_strlen(buff);
	res = (char*)malloc(sizeof(char) * (len + 1));
	while (line[i] != '\0')
	{
		res[i] = line[i];
		i++;
		j++;
	}
	while (buff)
	{
		res[i] = buff;
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(int fd)
{
	int		i;
	char	*line;
	char	buff[2];

	i = 0;
	buff[1] = '\0';
	line = NULL;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n')
	{
		line[i] = ft_strjoin(line, buff);
		i++;
	}
	return (line);
}
