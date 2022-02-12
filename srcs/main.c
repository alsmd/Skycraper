/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:46:56 by flda-sil          #+#    #+#             */
/*   Updated: 2022/02/12 16:40:46 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush.h>

int	main(int argc, char *argv[])
{
	t_rush	rush;
	if (argc < 6)
		return (0);
	
	if (!create_board(&rush, &argv[1]))
	{
		printf("Erro Creating Rule and Board!\n");
		return (0);
	}
	fill_square(&rush, 0, 0);
	/* if (map_is_right(&rush))
		printf("Mapa esta correto\n");
	else
		printf("Mapa esta incorreto\n");
	print_board(&rush); */
	return (0);
}
