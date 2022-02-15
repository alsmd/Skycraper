/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sight_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:50 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 15:13:48 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

/*
	@brief	Get the lower tower that is missing of active_line
*/
int	get_lower_tower(t_sky *sky, char *active_line)
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
		if (active_line[index] != 0)
			missing[active_line[index] - 1] = 10;
		index++;
	}
	index = 0;
	while (index < sky->size)
	{
		if (missing[index] < lower || lower == 0)
			lower = missing[index];
		index++;
	}
	free(missing);
	return (lower);
}

/*
	@brief	Get the higher tower that is missing of active_line
*/
int	get_higher_tower(t_sky *sky, char *active_line)
{
	char	*missing;
	int		higher;
	int		index;

	missing = (char *) ft_calloc(sky->size, sizeof(char));
	set_options(sky, missing);
	higher = 0;
	index = 0;
	while (index < sky->size)
	{
		if (active_line[index] != 0)
			missing[active_line[index] - 1] = 0;
		index++;
	}
	index = 0;
	while (index < sky->size)
	{
		if (missing[index] > higher)
			higher = missing[index];
		index++;
	}
	free(missing);
	return (higher);
}

int	get_towers_in_view(t_sky *sky)
{
	int	index;
	int	towers_in_view;
	int	higher_tower;

	towers_in_view = 0;
	higher_tower = 0;
	index = 0;
	while (index < sky->size)
	{
		if (sky->active_line[index] > higher_tower)
		{
			towers_in_view += 1;
			higher_tower = sky->active_line[index];
		}
			
		index++;
	}
	return (towers_in_view);
}

/*
	@brief	Check if a rule would see the right number of towers
			if the missing blocks were filled.
*/
int	check_missing_block(t_sky *sky, int has_to_see, int value)
{
	int	towers_in_view;
	int	index;
	int	tower;

	towers_in_view = sky->towers_in_view;
	index = 0;
	while (index < sky->size)
	{
		if (sky->active_line[index] == 0)
		{
			if (value == LOWER)
				tower = get_lower_tower(sky, sky->active_line);
			else
				tower = get_higher_tower(sky, sky->active_line);
			sky->active_line[index] = tower;
		}
		index++;
	}
	towers_in_view = get_towers_in_view(sky);
	if (has_to_see > towers_in_view && value == LOWER)
		return (1);
	if (has_to_see < towers_in_view && value == HIGHER)
		return (1);
	return (0);
}

/*
	@brief	Check if a rule is seeing the wrong number of towers
*/
int	wrong_sight(t_sky *sky, int has_to_see)
{
	if (has_to_see > sky->towers_in_view)
	{
		if (sky->missing_towers == 0 || \
			check_missing_block(sky, has_to_see, LOWER))
			return (1);
	}
	else if (has_to_see < sky->towers_in_view)
	{
		if (sky->missing_towers == 0 || \
			check_missing_block(sky, has_to_see, HIGHER))
			return (1);
	}
	return (0);
}
