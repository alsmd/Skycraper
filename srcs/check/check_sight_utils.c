/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sight_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:50 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 03:50:26 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

/*
	@brief	Get the lower tower that is missing of active_line
*/
int	get_lower_tower(t_rush *rush, char active_line[4])
{
	char	missing[4];
	int		lower;
	int		index;

	set_options(missing);
	lower = 0;
	index = 0;
	while (index < 4)
	{
		if (active_line[index] != 0)
			missing[active_line[index] - 1] = 10;
		index++;
	}
	index = 0;
	while (index < 4)
	{
		if (missing[index] < lower || lower == 0)
			lower = missing[index];
		index++;
	}
	return (lower);
}

/*
	@brief	Get the higher tower that is missing of active_line
*/
int	get_higher_tower(t_rush *rush, char active_line[4])
{
	char	missing[4];
	int		higher;
	int		index;

	set_options(missing);
	higher = 0;
	index = 0;
	while (index < 4)
	{
		if (active_line[index] != 0)
			missing[active_line[index] - 1] = 0;
		index++;
	}
	index = 0;
	while (index < 4)
	{
		if (missing[index] > higher)
			higher = missing[index];
		index++;
	}
	return (higher);
}

/*
	@brief	Check if a tower would be seen if it was in a specific posititon
*/
int	is_in_view(t_rush *rush, int tower, int index)
{
	while (index >= 0)
	{
		if (rush->active_line[index] > tower)
			return (0);
		index--;
	}
	return (1);
}

/*
	@brief	Check if a rule would see the right number of towers
			if the missing blocks were filled.
*/
int	check_missing_block(t_rush *rush, int has_to_see, int value)
{
	int	towers_in_view;
	int	index;
	int	tower;

	towers_in_view = rush->towers_in_view;
	index = 0;
	while (index < 4)
	{
		if (rush->active_line[index] == 0)
		{
			if (value == LOWER)
				tower = get_lower_tower(rush, rush->active_line);
			else
				tower = get_higher_tower(rush, rush->active_line);
			if (is_in_view(rush, tower, index))
				towers_in_view += 1;
			rush->active_line[index] = tower;
		}
		index++;
	}
	if (has_to_see > towers_in_view && value == LOWER)
		return (1);
	if (has_to_see > towers_in_view && value == HIGHER)
		return (1);
	return (0);
}

/*
	@brief	Check if a rule is seeing the wrong number of towers
*/
int	wrong_sight(t_rush *rush, int has_to_see)
{
	if (has_to_see > rush->towers_in_view)
	{
		if (rush->missing_towers == 0 || \
			check_missing_block(rush, has_to_see, LOWER))
			return (1);
	}
	if (has_to_see < rush->towers_in_view)
	{
		if (rush->missing_towers == 0 || \
			check_missing_block(rush, has_to_see, HIGHER))
			return (1);
	}
	return (0);
}
