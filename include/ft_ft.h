/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:09:52 by mdupuy            #+#    #+#             */
/*   Updated: 2016/09/20 20:59:38 by mdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_params_map
{
	int				nb_lines;
	char			vide;
	char			obs;
	char			rempli;
}					t_params_map;

#endif
