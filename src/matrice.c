/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:11:50 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:32 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_params_map	ft_get_params(int fd)
{
	char			buff[1];
	t_params_map	tmap;
	char			line1[200];
	int				i;
	int				j;

	i = 0;
	j = 0;
	tmap.nb_lines = 0;
	while (read(fd, buff, 1) != 0 && buff[0] != '\n')
	{
		line1[i] = buff[0];
		i++;
	}
	line1[i + 1] = '\0';
	tmap.rempli = line[i--];
	tmap.obs = line[i--];
	tmap.vide = line[i--];
	while (line[j] >= '0' && line[j] <= '9' && j < i)
	{
		tmap.nb_lines = tmap.nb_lines * 10 + line[j] - '0';
		j++;
	}
	return (tmap);
}
