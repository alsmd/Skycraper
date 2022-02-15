/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:00 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 18:27:17 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

/*
	@brief	Get the tower that was not used in this block,
			and is not been used in this line and column
*/
int	get_available_tower(t_sky *sky, int line, int col, char *used)
{
	char	*missing;
	int		lower;
	int		index;

	missing = (char *) ft_calloc(sky->size, sizeof(char));
	set_options(sky, missing);
	lower = 0;
	index = 0;
	while (index < sky->size)
	{
		if (sky->map[line][index] != 0)
			missing[sky->map[line][index] - 1] = 10;
		if (sky->map[index][col] != 0)
			missing[sky->map[index][col] - 1] = 10;
		index++;
	}
	index = 0;
	while (index < sky->size)
	{
		if ((missing[index] < lower || lower == 0) && \
			(!is_in(used, missing[index], sky->size) && missing[index] != 10))
			lower = missing[index];
		index++;
	}
	free(missing);
	return (lower);
}

/*
	@brief	fill sky->map[4][4] according to skyscraper's rules
			that is inside sky->rule[4][4] using backtracking.
*/
int	fill_square(t_sky *sky, int line, int col)
{
	int		tower;
	char	*tower_tried;

	tower_tried = ft_calloc(sky->size, sizeof(char));
	if (col == sky->size)
		return (fill_square(sky, line + 1, 0));
	if (line == sky->size)
		return (1);
	while (get_available_tower(sky, line, col, tower_tried))
	{
		tower = get_available_tower(sky, line, col, tower_tried);//1 2 0 0
		if (sky->map[line][col] == 0)
			sky->map[line][col] = tower;
		if (map_is_right(sky))
		{
			if (fill_square(sky, line, col + 1))
			{
				free(tower_tried);
				return (1);
			}
		}
		tower_tried[tower - 1] = tower;
		sky->map[line][col] = 0;
	}
	free(tower_tried);
	return (0);
}
