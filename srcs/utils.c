/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:06 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 03:53:31 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

/*
	@brief	Check if a character is inside an array.
*/
int	is_in(char *array, int c, int size)
{
	while (size--)
	{
		if (array[size] == c)
			return (1);
	}
	return (0);
}

/*
	@brief	Reset variables used to check rules
*/
void	reset(t_rush *rush)
{
	rush->higher_tower = 0;
	rush->missing_towers = 0;
	rush->towers_in_view = 0;
	rush->active_line[0] = 0;
	rush->active_line[1] = 0;
	rush->active_line[2] = 0;
	rush->active_line[3] = 0;
	rush->index = 0;
}

/*
	@brief	Set option to 1, 2, 3 and 4, that is
			the numbers that a tower can be
*/
void	set_options(char option[4])
{
	option[0] = 1;
	option[1] = 2;
	option[2] = 3;
	option[3] = 4;
}
