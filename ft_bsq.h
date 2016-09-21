/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:09:52 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:38 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_map
{
	int		**map;
	int		nb_lines;
	char		disp;
	char		obs;
	char		full;
}			t_map;

t_map			*get_map(char *file);
t_map			*ft_get_params(int fd);
int			*ft_strjoin_int1(char *line, char buff);
int			*ft_get_next_line(int fd, t_map *tmap);
int			ft_tab_len(int *tab);
int			ft_char_val(char buff, t_map *tmap);
void			ft_putchar(char c);

#endif
