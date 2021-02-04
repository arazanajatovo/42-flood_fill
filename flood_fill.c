/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flood_fill.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 12:05:12 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 14:10:33 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "t_point.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_point cbegin(int x, int y)
{
	t_point begin;

	begin.x = x;
	begin.y = y;
	return (begin);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	vide;

	vide = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	(begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == vide) ? flood_fill(tab, size, cbegin(begin.x - 1, begin.y)) : 0;
	(begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == vide) ? flood_fill(tab, size, cbegin(begin.x, begin.y - 1)) : 0;
	(begin.x + 1 <= size.x - 1 && tab[begin.y][begin.x + 1] == vide) ? flood_fill(tab, size, cbegin(begin.x + 1, begin.y)) : 0;
	(begin.y + 1 <= size.y - 1 && tab[begin.y + 1][begin.x] == vide) ? flood_fill(tab, size, cbegin(begin.x, begin.y + 1)) : 0;
}

int		main(void)
{
	int		i;
	int		j = 0;
	char	**area;
	char	*zone[] = {
		"11111111000110010110",
		"10000001050000004580",
		"10010001030397860070",
		"10110101000300500490",
		"10110101008005000500",
		"11100100008795000000"
	};
	t_point size = { 20, 6 };
	t_point begin = { 2, 2 };
	i = size.y - 1;
	area = (char**)malloc(sizeof(char*) * size.y + 1);
	while (i >= 0)
		area[i--] = (char*)malloc(sizeof(char) * size.x + 1);
	i = 0;
	while (i <= size.y - 1)
	{
		j = 0;
		while (j <= size.x - 1)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	area[size.y] = NULL;
	i = 0;
	while (area[i])
		printf("%s\n", area[i++]);
	flood_fill(area, size, begin);
	printf("\n");
	i = 0;
	while (area[i])
		printf("%s\n", area[i++]);
	return (0);
}
