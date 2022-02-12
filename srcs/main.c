/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:56 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 13:13:49 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

int	main(int argc, char *argv[])
{
	if (argc < 6)
		return (0);
	t_rush	rush = {
		.map = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
		},
		.rule = {
		{3, 1, 2, 3},//up
		{1, 3, 3, 2},//down
		{2, 3, 2, 1},//left
		{3, 2, 1, 2}//right
		}
	};
	create_board(&rush, &argv[1]);
	fill_square(&rush, 0, 0);
	if (map_is_right(&rush))
		printf("Mapa esta correto\n");
	else
		printf("Mapa esta incorreto\n");
	int	line = 0;
	int	col = 0;
	while (line < 4)
	{
		while (col < 4)
		{
			printf("%d ", rush.map[line][col]);
			col++;
		}
		printf("\n");
		col = 0;
		line++;
	}
	return (0);
}
