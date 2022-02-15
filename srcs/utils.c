/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:47:06 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 16:02:26 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sky.h>

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
void	reset(t_sky *sky)
{
	int	index;

	index = 0;
	sky->higher_tower = 0;
	sky->missing_towers = 0;
	sky->towers_in_view = 0;
	while (index < sky->size)
	{
		sky->active_line[index] = 0;
		sky->line_to_fill[index] = 0;
		index++;
	}
	sky->index = 0;
}

/*
	@brief	Set option to 1, 2, 3 and 4, that is
			the numbers that a tower can be
*/
void	set_options(t_sky *sky, char *option)
{
	int	index;

	index = 0;
	while (index < sky->size)
	{
		option[index] = index + 1;
		index++;
	}
}

void	print_board(t_sky *sky)
{
	int	line = 0;
	int	col = 0;
	while (line < sky->size)
	{
		while (col < sky->size)
		{
			printf("%d ", sky->map[line][col]);
			col++;
		}
		printf("\n");
		col = 0;
		line++;
	}
}