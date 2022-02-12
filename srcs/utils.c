/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:06 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 14:37:31 by flda-sil         ###   ########.fr       */
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
	int	index;

	index = 0;
	rush->higher_tower = 0;
	rush->missing_towers = 0;
	rush->towers_in_view = 0;
	while (index < rush->size)
	{
		rush->active_line[index] = 0;
		index++;
	}
	rush->index = 0;
}

/*
	@brief	Set option to 1, 2, 3 and 4, that is
			the numbers that a tower can be
*/
void	set_options(t_rush *rush, char *option)
{
	int	index;

	index = 0;
	while (index < rush->size)
	{
		option[index] = index + 1;
		index++;
	}
}

void	print_board(t_rush *rush)
{
	int	line = 0;
	int	col = 0;
	while (line < rush->size)
	{
		while (col < rush->size)
		{
			printf("%d ", rush->map[line][col]);
			col++;
		}
		printf("\n");
		col = 0;
		line++;
	}
	printf("\n\n");
}