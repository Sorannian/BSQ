/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:03:37 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:29 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

int	ft_char_val(char buff, t_map *tmap)
{
	if (buff == tmap->obs)
		return (0);
	else if (buff == tmap->disp)
		return (1);
	return (-1);
}

int	*ft_strjoin_int(int *line, char buff, t_map *tmap)
{
	int		*res;
	int		len;
	int		i;

	i = 0;
	if (line != NULL)
	{
		len = ft_tab_len(line) + 1;
		if ((res = (int*)malloc(sizeof(int) * (len + 1))) == NULL)
			return (NULL);
		while (line[i] >= 0)
		{
			res[i] = line[i];
			i++;
		}
		free(line);
	}
	else
		if ((res = (int*)malloc(sizeof(int) * 2)) == NULL)
			return (NULL);
	if ((res[i] = ft_char_val(buff, tmap)) == -1)
		return (NULL);
	res[++i] = -1;
	return (res);
}

int	*ft_get_next_line(int fd, t_map *tmap)
{
	int		i;
	int		*line;
	char		buff[1];

	i = 0;
	line = NULL;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n')
		if ((line = ft_strjoin_int(line, *buff, tmap)) == NULL)
			return (NULL);
	return (line);
}

t_map    	*get_map(char *file)
{
	int    		fd;
	t_map   	*tmap;
	int    		j;
	int    		len;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if ((tmap = ft_get_params(fd)) == NULL)
		return (NULL);
	j = 0;
	if ((tmap->map = (int**)malloc(sizeof(int *) * tmap->nb_lines)) == NULL)
		return (NULL);
	if ((tmap->map[j++] = ft_get_next_line(fd, tmap)) == NULL)
		return (NULL);
	len = ft_tab_len(tmap->map[0]);
	while (j < tmap->nb_lines)
		if ((tmap->map[j] = ft_get_next_line(fd, tmap)) == NULL || \
				ft_tab_len(tmap->map[j++]) != len)
			return (NULL);
	if (ft_get_next_line(fd, tmap) != NULL)
		return (NULL);
	close(fd);
	return (tmap);
}
