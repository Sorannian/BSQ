/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:11:50 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:32 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

t_map	*ft_get_params(int fd)
{
	char		buff[1];
	t_map		*tmap;
	char		line[100];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((tmap = (t_map*)malloc(sizeof(tmap))) == NULL)
		return (NULL);
	tmap->nb_lines = 0;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n' && i < 99)
		line[i++] = buff[0];
	line[i] = '\0';
	tmap->full = line[--i];
	tmap->obs = line[--i];
	tmap->disp = line[--i];
	if (tmap->full == tmap->disp || tmap->full == tmap->obs || \
		tmap->disp == tmap->obs)
		return (NULL);
	while (line[j] >= '0' && line[j] <= '9' && j < i)
		tmap->nb_lines = tmap->nb_lines * 10 + line[j++] - '0';
	if (j != i)
		return (NULL);
	return (tmap);
}
