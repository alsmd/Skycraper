/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:00 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 15:19:14 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

/*
	@brief	fill rush->map[4][4] according to skyscraper's rules
			that is inside rush->rule[4][4] using backtracking.
*/
int	fill_square(t_rush *rush, int line, int col)
{
	int		tower;//to do: keep track of numbers that was alredy used

	tower = 1;
	if (col == rush->size)
		return (fill_square(rush, line + 1, 0));
	if (line == rush->size)
		return (1);
	while (tower <= rush->size)
	{
		if (rush->map[line][col] == 0)
			rush->map[line][col] = tower;
		if (map_is_right(rush))
		{
			if (fill_square(rush, line, col + 1))
				return (1);
		}
		rush->map[line][col] = 0;
		tower += 1;
	}
	return (0);
}
