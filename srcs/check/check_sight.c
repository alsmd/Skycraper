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

#include <rush.h>

/*
	@brief	Keep track of:
				ºhigher_tower, 
				ºtowers_in_view, 
				ºmissing_towers, 
				°active_line, 
*/
void	check_block(t_rush *rush, int line, int col)
{
	if (rush->map[line][col] > rush->higher_tower)
	{
		rush->higher_tower = rush->map[line][col];
		rush->towers_in_view += 1;
	}
	if (rush->map[line][col] == 0)
		rush->missing_towers += 1;
	rush->active_line[rush->index] = rush->map[line][col];
	rush->index += 1;
}

/*
	@brief	Check column down rule
*/
int	check_coldown(t_rush *rush)
{
	int	col;
	int	line;

	col = 0;
	line = rush->size - 1;
	reset(rush);
	while (col < rush->size)
	{
		while (line >= 0)
		{
			if (is_in(rush->active_line, rush->map[line][col], rush->size) && \
				rush->map[line][col] != 0)
				return (0);
			check_block(rush, line, col);
			line -= 1;
		}
		if (wrong_sight(rush, rush->rule[1][col] - 48))
			return (0);
		reset(rush);
		line = rush->size - 1;
		col += 1;
	}
	return (1);
}

/*
	@brief	Check column up rule
*/
int	check_colup(t_rush *rush)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	reset(rush);
	while (col < rush->size)
	{
		while (line < rush->size)
		{
			if (is_in(rush->active_line, rush->map[line][col], rush->size) && \
				rush->map[line][col] != 0)
				return (0);
			check_block(rush, line, col);
			line += 1;
		}
		if (wrong_sight(rush, rush->rule[0][col] - 48))
			return (0);
		reset(rush);
		line = 0;
		col += 1;
	}
	return (1);
}

/*
	@brief	Check row left rule
*/
int	check_rowleft(t_rush *rush)
{
	int	col;
	int	line;

	col = 0;
	line = 0;
	reset(rush);
	while (line < rush->size)
	{
		while (col < rush->size)
		{
			if (is_in(rush->active_line, rush->map[line][col], rush->size) && \
				rush->map[line][col] != 0)
				return (0);
			check_block(rush, line, col);
			col += 1;
		}
		if (wrong_sight(rush, rush->rule[2][line] - 48))
			return (0);
		reset(rush);
		col = 0;
		line += 1;
	}
	return (1);
}

/*
	@brief	Check row right rule
*/
int	check_rowright(t_rush *rush)
{
	int	col;
	int	line;

	col = rush->size - 1;
	line = 0;
	reset(rush);
	while (line < rush->size)
	{
		while (col >= 0)
		{
			if (is_in(rush->active_line, rush->map[line][col], rush->size) && \
				rush->map[line][col] != 0)
				return (0);
			check_block(rush, line, col);
			col -= 1;
		}
		if (wrong_sight(rush, rush->rule[3][line] - 48))
			return (0);
		reset(rush);
		col = rush->size - 1;
		line += 1;
	}
	return (1);
}
