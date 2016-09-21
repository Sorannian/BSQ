/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:00:43 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 16:41:27 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_bsq.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_free_tmap(t_map *tmap)
{
	int	i;

	i = 0;
	while (i < tmap->nb_lines)
		free(tmap->map[i++]);
	free(tmap->map);
	free(tmap);
}

int		main(int ac, char **av)
{
	t_map		*tmap;
	int		i;
	int		j;

	if (ac >= 2)
	{
		i = 0;
		if ((tmap = get_map(av[1])) == NULL)
		{
			write(1, "map error\n", 10);
			return (0);
		}
		while (i < tmap->nb_lines)
		{
			j = 0;
			while (tmap->map[i][j] != -1)
				ft_putchar('0' + tmap->map[i][j++]);
			ft_putchar('\n');
			i++;
		}
		ft_free_tmap(tmap);
	}
	return (0);
}
