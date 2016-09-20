/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitrosse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:29:41 by kitrosse          #+#    #+#             */
/*   Updated: 2016/09/19 18:29:42 by kitrosse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_resolve(int **tab)
{
	int x;
	int	y;
	int xm;
	int ym;

	x = 1;
	y = 1;
	xm = 1;
	ym = 1;
	while (y != 0)
	{
		if (tab[x][y] == '\n')
		{
			y++;
			x = 1;
		}
		if (tab[x][y] == 0)
			x++;
		if (tab[x][y] > 0)
			tab[x][y] += ft_min(tab, x, y);
		if (tab[x][y] > tab[xm][ym])
		{
			xm = x;
			ym = y;
		}
		x++;
	}
	ft_put
}

int		ft_min(int **tab, int x, int y)
{
	int i;
	int j;
	int k;

	i = tab[x -1][y]
	j = tab[x][y -1]
	k = tab[x -1][y -1]
	if ((i <= j && j <= k) || (k <= j && j <= i))
		return (j);
	if ((j <= i && i <= k) || (k <= i && i <= j))
		return (i);
	if ((i <= k && k <= j) || (j <= k && k <= i))
		return (k);
	return (0);
}

void	ft_put(int **tab, int xm, int ym)
{
	int a;
	int b;

	a = xm - tab[xm][ym];
	b = ym - tab[xm][ym];
	while(b != ym)
	{
		if(a == xm)
		{
			a = xm - ;
			b++;
		}
		ft_putchar("a voir");
		a++;
	}
}