/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:15 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 14:49:49 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

/*
	@brief	Keep track of:
				ºhigher_tower, 
				ºtowers_in_view, 
				ºmissing_towers, 
				°active_line, 
*/
void	check_block(t_sky *sky, int line, int col)
{
	if (sky->map[line][col] > sky->higher_tower)
	{
		sky->higher_tower = sky->map[line][col];
		sky->towers_in_view += 1;
	}
	if (sky->map[line][col] == 0)
		sky->missing_towers += 1;
	sky->active_line[sky->index] = sky->map[line][col];
	sky->index += 1;
}

/*
	@brief	Check column down rule
*/
int	check_coldown(t_sky *sky)
{
	int	col;
	int	line;

	col = 0;
	line = sky->size - 1;
	reset(sky);
	while (col < sky->size)
	{
		while (line >= 0)
		{
			if (is_in(sky->active_line, sky->map[line][col], sky->size) && \
				sky->map[line][col] != 0)
				return (0);
			check_block(sky, line, col);
			line -= 1;
		}
		if (wrong_sight(sky, sky->rule[1][col] - 48))
			return (0);
		reset(sky);
		line = sky->size - 1;
		col += 1;
	}
	return (1);
}

/*
	@brief	Check column up rule
*/
int	check_colup(t_sky *sky)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	reset(sky);
	while (col < sky->size)
	{
		while (line < sky->size)
		{
			if (is_in(sky->active_line, sky->map[line][col], sky->size) && \
				sky->map[line][col] != 0)
				return (0);
			check_block(sky, line, col);
			line += 1;
		}
		if (wrong_sight(sky, sky->rule[0][col] - 48))
			return (0);
		reset(sky);
		line = 0;
		col += 1;
	}
	return (1);
}

/*
	@brief	Check row left rule
*/
int	check_rowleft(t_sky *sky)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	reset(sky);
	while (line < sky->size)
	{
		while (col < sky->size)
		{
			if (is_in(sky->active_line, sky->map[line][col], sky->size) && \
				sky->map[line][col] != 0)
				return (0);
			check_block(sky, line, col);
			col += 1;
		}
		if (wrong_sight(sky, sky->rule[2][line] - 48))
			return (0);
		reset(sky);
		col = 0;
		line += 1;
	}
	return (1);
}

/*
	@brief	Check row right rule
*/
int	check_rowright(t_sky *sky)
{
	int	col;
	int	line;

	col = sky->size - 1;
	line = 0;
	reset(sky);
	while (line < sky->size)
	{
		while (col >= 0)
		{
			if (is_in(sky->active_line, sky->map[line][col], sky->size) && \
				sky->map[line][col] != 0)
				return (0);
			check_block(sky, line, col);
			col -= 1;
		}
		if (wrong_sight(sky, sky->rule[3][line] - 48))
			return (0);
		reset(sky);
		col = sky->size - 1;
		line += 1;
	}
	return (1);
}
