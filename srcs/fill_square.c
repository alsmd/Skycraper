/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:00 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 13:03:11 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

/*
	@brief	fill rush->map[4][4] according to skyscraper's rules
			that is inside rush->rule[4][4] using backtracking.
*/
int	fill_square(t_rush *rush, int line, int col)
{
	char	options[4];
	int		index;

	index = 0;
	set_options(options);
	if (col == 4)
		return (fill_square(rush, line + 1, 0));
	if (line == 4)
		return (1);
	while (index < 4)
	{
		if (rush->map[line][col] == 0)
			rush->map[line][col] = options[index];
		if (map_is_right(rush))
		{
			if (sort(rush, line, col + 1))
				return (1);
		}
		rush->map[line][col] = 0;
		index += 1;
	}
	return (0);
}
